#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 200005, BASE = 1 << 18;

int tree[2 * BASE + 5];
int n, from[N], to[N];
vector<int> begins[N], Ends[N];
int ans1[N], ans2[N];
int who[N];

void insert(int pos, int w) {
    pos += BASE;
    while (pos) {
        tree[pos] += w;
        pos /= 2;
    }
}

int query(int posa, int posb) {
    if (posa > posb) return 0;
    posa += BASE;
    posb += BASE;
    int ret = tree[posa];
    if (posa != posb) {
        ret += tree[posb];
    }
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret += tree[posa + 1];
        }
        if (posb % 2 == 1) {
            ret += tree[posb - 1];
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

int find(int posa, int posb, int w = 1, int from = 0, int to = BASE - 1) {
    if (posb < from) {
        return -1;
    }
    if (posa > to) {
        return -1;
    }
    if (tree[w] == 0) {
        return -1;
    }
    if (w >= BASE) {
        return w - BASE;
    }
    int mid = (from + to) / 2;
    return max(find(posa, posb, 2 * w, from, mid), find(posa, posb, 2 * w + 1, mid + 1, to));
}

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &from[i], &to[i]);
        begins[from[i]].push_back(i);
        Ends[to[i]].push_back(i);
    }
    
    priority_queue<pair<int, pair<int, int>> > Q;
    for (int i = 1; i <= n; i++) {
        for (int x : begins[i]) {
            Q.push({-to[x], {from[x], x}});
        }
        assert(!Q.empty());
        int w = Q.top().second.second;
        Q.pop();
        ans1[w] = i;
        who[i] = w;
    }
    
    bool diff = false;
    for (int i = 1; i <= n; i++) {
        for (int x : begins[i]) {
            insert(ans1[x], 1);
        }
        
        int me = who[i];
        if (query(from[me], i - 1) > 0) {
            int kto = find(from[me], i - 1);
            debug(kto);
            for (int j = 1; j <= n; j++) {
                ans2[j] = ans1[j];
            }
            ans2[me] = kto;
            ans2[who[kto]] = i;
            diff = true;
            break;
        }
        
        for (int x : Ends[i]) {
            insert(ans1[x], -1);
        }
    }
    
    if (!diff) {
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            printf("%d ", ans1[i]);
        }
        printf("\n");
    } else {
        
        printf("NO\n");
        for (int i = 1; i <= n; i++) {
            printf("%d ", ans1[i]);
        }
        printf("\n");
        for (int i = 1; i <= n; i++) {
            printf("%d ", ans2[i]);
        }
        printf("\n");
    }
 
    return 0;
}