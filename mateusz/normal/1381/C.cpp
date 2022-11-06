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

const int N = 100005;

int n, x, y;
int tab[N], ans[N];
vector<int> pos[N];
bool good[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &x, &y);
        for (int i = 1; i <= n + 1; i++) {
            pos[i].clear();
        }
        y -= x;
        priority_queue<pair<int, int> > Q;
        for (int i = 1; i <= n; i++) {
            ans[i] = -1;
            scanf("%d", &tab[i]);
            pos[tab[i]].push_back(i);
            good[i] = false;
        }
        int mex = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (pos[i].empty()) {
                mex = i;
            } else {
                Q.push({pos[i].size(), i});
            }
        }
        if (x + y > n) {
            debug("LOL");
            printf("NO\n");
            continue;
        }
        for (int i = 1; i <= x; i++) {
            int col = Q.top().second;
            Q.pop();
            int p = pos[col].back();
            good[p] = true;
            pos[col].pop_back();
            Q.push({pos[col].size(), col});
        }
        
        vector<int> colors;
        for (int i = 1; i <= n + 1; i++) {
            if (pos[i].empty()) continue;
            colors.push_back(i);
        }
        sort(colors.begin(), colors.end(), [&](int a, int b) { return pos[a].size() > pos[b].size(); });
        bool bad = false;
        vector<int> priority(n + 5, 0);
        for (int i = 0; i < colors.size(); i++) {
            priority[colors[i]] = i;
        }
        set<pair<int, int> > freePositions;
        for (int i = 1; i <= n; i++) {
            if (!good[i]) {
                freePositions.insert({priority[tab[i]], i});
            }
        }
        int remaining = n - x - y;
        debug(remaining);
        for (auto col : colors) {
            auto posOld = pos[col];
            while (remaining > 0 && !pos[col].empty()) {
                remaining--;
                pos[col].pop_back();
            }
//             debug(col, pos[col].size(), n - x - (int)posOld.size());
            if ((int)pos[col].size() > n - x - (int)posOld.size()) {
                bad = true;
                break;
            }
            
            set<int> removed;
            for (auto x : posOld) {
                if (freePositions.count({priority[col], x})) {
                    freePositions.erase({priority[col], x});
                    removed.insert(x);
                }
            }
            for (auto x : pos[col]) {
                auto freePos = *(--freePositions.end());
                ans[freePos.second] = col;
                freePositions.erase(freePos);
            }
            
            for (auto x : removed) {
                freePositions.insert({priority[col], x});
            }
        }
        if (bad) {
            printf("NO\n");
            continue;
        }
        
        for (int i = 1; i <= n; i++) {
            if (ans[i] != -1) continue;
            if (good[i]) {
                ans[i] = tab[i];
            } else {
                ans[i] = mex;
            }
        }
        
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            printf("%d ", ans[i]);
        }
       
        printf("\n");
    }
    
    return 0;
}