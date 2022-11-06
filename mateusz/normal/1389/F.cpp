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

const int N = 400005, BASE = (1 << 19);

int tree[2][2 * BASE + 5];
int dod[2][2 * BASE + 5];

int n;
int from[N], to[N], color[N];

void add(int col, int pos) {
    pos += BASE;
    while (pos >= 1) {
        if (pos % 2 == 0) {
        dod[col][pos + 1]++;
        tree[col][pos + 1]++;
        }
        pos /= 2;
        tree[col][pos] = max(tree[col][2 * pos], tree[col][2 * pos + 1]) + dod[col][pos];
    }
}

void insert(int pos, int w) {
    pos += BASE;
    while (pos >= 1) {
        tree[0][pos] = max(tree[0][pos], w);
        tree[1][pos] = max(tree[1][pos], w);
        pos /= 2;
    }
}

int query() {
    debug(tree[0][1], tree[1][1]);
    return max(tree[0][1], tree[1][1]);
}

int main() {
    
    scanf("%d", &n);
    
    vector<pair<int, pair<int, int>>> renum;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &from[i], &to[i], &color[i]);
        color[i]--;
        renum.push_back({from[i], {i, 0}});
        renum.push_back({to[i], {i, 1}});
    }
    sort(renum.begin(), renum.end());
    
    int id = 0;
    for (int i = 0; i < renum.size(); i++) {
        if (i == 0 || renum[i].first != renum[i - 1].first) {
            id++;
        }
        if (renum[i].second.second == 0) {
            from[renum[i].second.first] = id;
        } else {
            to[renum[i].second.first] = id;
        }
    }
    
    vector<pair<int, int>> events;
    
    for (int i = 1; i <= n; i++) {
        debug(from[i], to[i]);
        events.push_back({from[i], i});
    }
    
    int ans = 0;
    sort(events.begin(), events.end());
    for (int i = events.size() - 1; i >= 0; i--) {
        int low = events[i].first;
        int w = events[i].second;
        add(color[w], to[w]);
        int dp = query();
        debug(i, dp);
        ans = max(ans, dp);
        insert(low, dp);
    }
    
    ans = max(ans, query());
    printf("%d\n", ans);
    
    return 0;
}