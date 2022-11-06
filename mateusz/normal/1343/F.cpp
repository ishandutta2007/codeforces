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

const int N = 205;

int n, ile;
set<set<int>> allSets;
int cnt[N][N];
set<int> sets[N];
vector<int> neighs[N];



int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        allSets.clear();
        for (int i = 1;  i <= n; i++) {
            neighs[i].clear();
            sets[i].clear();
            for (int j = 1; j <= n; j++) {
                cnt[i][j] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            scanf("%d", &ile);
            for (int j = 1; j <= ile; j++) {
                int x;
                scanf("%d", &x);
                sets[i].insert(x);
            }
            allSets.insert(sets[i]);
            for (auto w : sets[i]) {
                for (auto u : sets[i]) {
                    neighs[w].push_back(u);
                    cnt[w][u]++;
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            sort(neighs[i].begin(), neighs[i].end(), [&](int a, int b) { return cnt[i][a] > cnt[i][b]; });
            neighs[i].resize(unique(neighs[i].begin(), neighs[i].end()) - neighs[i].begin());
        }
        
        vector<int> eee;
        for (int i = 1; i <= n; i++) {
            eee.push_back(i);
        }
        random_shuffle(eee.begin(),eee.end());
        
        for (int i = 1; i <= n; i++) {
            vector<int> per;
            int w = i;
            set<int> values;
            values.insert(w);
            per.push_back(w);
            bool bad = false;
            auto allSetsCopy = allSets;
            for (int j = 2; j <= n; j++) {
                debug(per);
                int nxt = -1;
                for (int u : neighs[w]) {
                    if (!values.count(u)) {
                        nxt = u;
                        break;
                    }
                }
                if (nxt == -1) {
                    bad = true;
                    break;
                }
                per.push_back(nxt);
                values.insert(nxt);
                w = nxt;
                
                
                set<int> elo;
                bool found = false;
                for (int k = j - 1; k >= 0; k--) {
                    elo.insert(per[k]);
                    auto it = allSets.find(elo);
                    if (it != allSets.end()) {
                        found = true;
                        allSets.erase(it);
                        break;
                    }
                }
                if (!found) {
                    bad = true;
                    break;
                }
                
            }
            debug(per);
            debug(bad);
            
            allSets = allSetsCopy;
            if (!bad) {
                for (int x : per) {
                    printf("%d ", x);
                }
                printf("\n");
                break;
            }
        }
        
    }
    
    return 0;
}