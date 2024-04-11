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

const int N = (1 << 20) + 5;

int n, A[N], B[N];
bool vis[N];
int deg[N];
vector<int> G[N];

void DFS(int w) {
    vis[w] = true;
    for (int u : G[w]) {
        if (!vis[u]) DFS(u);
    }
}


bool good(int bits) {
    int m = (1 << bits);
    for (int i = 0; i < m; i++) {
        vis[i] = false;
        G[i].clear();
        deg[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int a = A[i] & (m - 1);
        int b = B[i] & (m - 1);
        G[a].push_back(b);
        G[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for (int i = 0; i < m; i++) {
        if (deg[i] % 2 == 1) return false;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (deg[i] > 0 && !vis[i]) {
            DFS(i);
            cnt++;
        }
        if (cnt > 1) return false;
    }
    return true;
}

vector<int> s;
vector<pair<int, int> > V[N];
bool removed[N];
void euler(int w) {
    debug(w);
    debug(V[w]);
    while (!V[w].empty()) {
        int u = V[w].back().first;
        int id = V[w].back().second;
        V[w].pop_back();
        if (removed[id]) continue;
        removed[id] = true;
        euler(u);
    }
    s.push_back(w);
}

bool done[N];

map<pair<int, int>, vector<pair<int, int>>> edges;
void solve(int bits) {
    debug(bits);
    int m = (1 << bits);
    for (int i = 1; i <= n; i++) {
        int a = A[i] & (m - 1);
        int b = B[i] & (m - 1);
        edges[{a, b}].push_back({2 * i - 1, 2 * i});
        edges[{b, a}].push_back({2 * i, 2 * i - 1});
        V[a].push_back({b, i});
        V[b].push_back({a, i});
    }
    for (int i = 0; i < m; i++) {
        if (V[i].size() > 0) {
            euler(i);
            break;
        }
    }
    debug(s);
    printf("%d\n", bits);
    for (int i = 0; i + 1 < s.size(); i++) {
        debug(i, s.size());
        int a = s[i];
        int b = s[i + 1];
        auto &v = edges[{a, b}];
        while (!v.empty() && done[v.back().first]) v.pop_back();
        int x = v.back().first;
        int y = v.back().second;
        done[x] = true;
        done[y] = true;
        printf("%d %d ", x, y);
    }
    printf("\n");
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &A[i], &B[i]);
    }
    
    int low = 1;
    int high = 20;
    int res = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (good(mid)) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    debug("LOL");
    solve(res);
    
    return 0;
}