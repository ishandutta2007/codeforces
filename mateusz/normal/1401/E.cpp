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

const int N = 100005, MX = 1000000, BASE = 1048576;

int tree[2 * BASE + 5];

void insert(int pos, int w) {
    pos += BASE;
    while (pos >= 1) {
        tree[pos] += w;
        pos /= 2;
    }
}

int query(int posa, int posb) {
    posa += BASE;
    posb += BASE;
    if (posa > posb) {
        return 0;
    }
    int ret = tree[posa];
    if (posa != posb) {
        ret += tree[posb];
    }
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret += tree[posa + 1];
        }
        if (posb % 2 == 1) {
            ret += tree[posb- 1];
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

int n, m;
int hy[N], hfrom[N], hto[N];
int wx[N], wfrom[N], wto[N];
vector<int> begins[MX + 5], Ends[MX + 5], hor[MX + 5];

int main() {
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &hy[i], &hfrom[i], &hto[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &wx[i], &wfrom[i], &wto[i]);
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        hor[hy[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        if (wfrom[i] == 0 && wto[i] == MX) {
            ans++;
        }
        begins[wfrom[i]].push_back(i);
        Ends[wto[i]].push_back(i);
    } 
    
    for (int i = 0; i <= MX; i++) {
        for (auto w : begins[i]) {
            insert(wx[w], 1);
        }
        
        for (auto w : hor[i]) {
            ans += query(hfrom[w], hto[w]);
            if (hfrom[w] == 0 && hto[w] == MX) {
                ans++;
            }
        }
        
        for (auto w : Ends[i]) {
            insert(wx[w], -1);
        }
    }
    
    printf("%lld\n", ans + 1);
    return 0;
}