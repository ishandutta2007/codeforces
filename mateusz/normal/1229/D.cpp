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
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 200005;

int n, k;
map<vector<int>, int> perID;
vector<int> myPerm[150];
int x;
int firstNext[150];
vector<int> pos[150];
int tab[N];
bool vis[150], visAdded[150];
int graf[150][150];

vector<int> zloz(vector<int> a, vector<int> b) {
    vector<int> c(a.size());
    for (int i = 0; i < a.size(); i++) {
        c[b[i] - 1] = a[i];
    }
    return c;
}

int main() {
    
    scanf("%d %d", &n, &k);
    
    vector<int> per;
    int kFact = 1;
    for (int i = 1; i <= k; i++) {
        per.push_back(i);
        kFact *= i;
    }
    
    int cnt = 0;
    do {
        perID[per] = ++cnt;
        myPerm[cnt] = per;
    } while (next_permutation(per.begin(), per.end()));
    
    for (int i = 1; i <= n; i++) {
        per.clear();
        for (int j = 1; j <= k; j++) {
            scanf("%d", &x);
            per.push_back(x);
        }
        int id = perID[per];
        tab[i] = id;
        pos[id].push_back(i);
    }
    
    for (int i = 1; i <= kFact; i++) pos[i].push_back(n + 1);
    
    for (int i = 1; i <= kFact; i++) {
        for (int j = 1; j <= kFact; j++) {
            auto perm = myPerm[i];
            auto perm2 = myPerm[j];
            auto perm3 = zloz(perm, perm2);
            graf[i][j] = perID[perm3];
        }
    }
    
    for (int j = 1; j <= kFact; j++) {
            firstNext[j] = 0;
        }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        
        
        for (int j = 1; j <= kFact; j++) {
            vis[j] = false;
            visAdded[j] = false;
        }
        vis[1] = true;
        int last = i;
        vector<int> added = {1};
        for (int visCnt = 0; visCnt <= kFact; visCnt++) {
            int closest = n + 1;
            for (int j = 1; j <= kFact; j++) {
                if (vis[j] == false) {
                    closest = min(closest, pos[j][firstNext[j]]);
                }
            }
            ans += (long long)(closest - last) * added.size();
            last = closest;
            if (closest == n + 1) break;
             
            vector<int> addCpy = {tab[closest]};
            while (!addCpy.empty()) {
                vector<int> newAdd;
                for (auto curId : addCpy) {
                    added.push_back(curId);
                    vis[curId] = true;
                    for (auto pId : added) {
                        int id = graf[pId][curId];
                        if (!vis[id]) {
                            vis[id] = true;
                            newAdd.push_back(id);
                        }
                        id = graf[curId][pId];
                        if (!vis[id]) {
                            vis[id] = true;
                            newAdd.push_back(id);
                        }
                    }
                }
                addCpy = newAdd;
            }
        }
        firstNext[tab[i]]++;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}