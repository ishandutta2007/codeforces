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

int n, ver[N][3];
bool vis[N];
map<pair<pair<int, int>, int>, int> triangles;
vector<int> sas[N];
vector<int> per, ansTr, s;
vector<int> V[N];

void DFS(int w) {
    s.push_back(w);
    vis[w] = true;
    per.push_back(w);
    while (s.size() >= 3 && triangles.count({{s[s.size() - 1], s[s.size() - 2]}, s[s.size() - 3]})) {
        ansTr.push_back(triangles[{{s[s.size() - 1], s[s.size() - 2]}, s[s.size() - 3]}]);
        swap(s.back(), s[s.size() - 2]);
        s.pop_back();
    }
    for (int u : V[w]) {
        if (!vis[u]) DFS(u);
    }
}


int main() {
    
    int tests;
    scanf("%d", &tests);
    while (tests--) {
        per.clear();
        ansTr.clear();
        s.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            V[i].clear();
            vis[i] = false;
            sas[i].clear();
        }
        triangles.clear();
        for (int i = 1; i <= n - 2; i++) {
            scanf("%d %d %d", &ver[i][0], &ver[i][1], &ver[i][2]);
            sas[ver[i][0]].push_back(ver[i][1]);
            sas[ver[i][0]].push_back(ver[i][2]);
            sas[ver[i][1]].push_back(ver[i][0]);
            sas[ver[i][1]].push_back(ver[i][2]);
            sas[ver[i][2]].push_back(ver[i][0]);
            sas[ver[i][2]].push_back(ver[i][1]);
            int a = ver[i][0];
            int b = ver[i][1];
            int c = ver[i][2];
            triangles[{{a, b}, c}] = i;
            triangles[{{b, c}, a}] = i;
            triangles[{{c, a}, b}] = i;
            triangles[{{c, b}, a}] = i;
            triangles[{{b, a}, c}] = i;
            triangles[{{a, c}, b}] = i;
        }
        for (int i = 1; i <= n; i++) {
            sort(sas[i].begin(), sas[i].end());
            for (int j = 0; j < sas[i].size(); j++) {
                if ((j == 0 || sas[i][j] != sas[i][j - 1]) && (j + 1 == sas[i].size() || sas[i][j] != sas[i][j + 1])) {
                    V[i].push_back(sas[i][j]);
                }
            }
        }
        DFS(1);
        for (int x : per) {
            printf("%d ", x);
        }
        printf("\n");
        
        for (int x : ansTr) {
            printf("%d ", x);
        }
        printf("\n");
    }
    
    return 0;
}