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

const int N = 100005;

int n;
int x[N], y[N], z[N];

map<pair<int, int>, vector<pair<int, int> > > naX, naY, naZ;
map<int, vector<pair<pair<int, int>, int> > > naXY, naXZ, naYZ;
vector<pair<pair<pair<int, int>, int>, int> > naNic;
bool done[N];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
        naX[{y[i], z[i]}].push_back({x[i], i});
        naY[{x[i], z[i]}].push_back({y[i], i});
        naZ[{x[i], y[i]}].push_back({z[i], i});
        naXY[z[i]].push_back({{x[i], y[i]}, i});
        naXZ[y[i]].push_back({{x[i], z[i]}, i});
        naYZ[x[i]].push_back({{y[i], z[i]}, i});
        naNic.push_back({{{x[i], y[i]}, z[i]}, i});
    }
    
    for (auto& it : naX) {
        sort(it.second.begin(), it.second.end());
    }
    for (auto& it : naY) {
        sort(it.second.begin(), it.second.end());
    }
    for (auto& it : naZ) {
        sort(it.second.begin(), it.second.end());
    }
    for (auto& it : naXY) {
        sort(it.second.begin(), it.second.end());
    }
    for (auto& it : naXZ) {
        sort(it.second.begin(), it.second.end());
    }
    for (auto& it : naYZ) {
        sort(it.second.begin(), it.second.end());
    }
    
    sort(naNic.begin(), naNic.end());
    
    
    vector<pair<int, int> > ans;
    for (auto& it : naX) {
        int lastId = -1;
        for (auto p : it.second) {
            int id = p.second;
            if (done[id]) continue;
            if (lastId == -1) {
                lastId = id;
                continue;
            }
            ans.push_back({lastId, id});
            done[lastId] = done[id] = true;
            lastId = -1;
        }
    }
    for (auto& it : naY) {
        int lastId = -1;
        for (auto p : it.second) {
            int id = p.second;
            if (done[id]) continue;
            if (lastId == -1) {
                lastId = id;
                continue;
            }
            ans.push_back({lastId, id});
            done[lastId] = done[id] = true;
            lastId = -1;
        }
    }
    for (auto& it : naZ) {
        int lastId = -1;
        for (auto p : it.second) {
            int id = p.second;
            if (done[id]) continue;
            if (lastId == -1) {
                lastId = id;
                continue;
            }
            ans.push_back({lastId, id});
            done[lastId] = done[id] = true;
            lastId = -1;
        }
    }
    for (auto& it : naXY) {
        int lastId = -1;
        for (auto p : it.second) {
            int id = p.second;
            if (done[id]) continue;
            if (lastId == -1) {
                lastId = id;
                continue;
            }
            ans.push_back({lastId, id});
            done[lastId] = done[id] = true;
            lastId = -1;
        }
    }
    for (auto& it : naXZ) {
        int lastId = -1;
        for (auto p : it.second) {
            int id = p.second;
            if (done[id]) continue;
            if (lastId == -1) {
                lastId = id;
                continue;
            }
            ans.push_back({lastId, id});
            done[lastId] = done[id] = true;
            lastId = -1;
        }
    }
    for (auto& it : naYZ) {
        int lastId = -1;
        for (auto p : it.second) {
            int id = p.second;
            if (done[id]) continue;
            if (lastId == -1) {
                lastId = id;
                continue;
            }
            ans.push_back({lastId, id});
            done[lastId] = done[id] = true;
            lastId = -1;
        }
    }
    
    int lastId = -1;
    for (auto p : naNic) {
        int id = p.second;
        if (done[id]) continue;
        if (lastId == -1) {
            lastId = id;
            continue;
        }
        ans.push_back({lastId, id});
        done[lastId] = done[id] = true;
        lastId = -1;
    }
    
    for (auto p : ans) {
        printf("%d %d\n", p.first, p.second);
    }
    
    return 0;
}