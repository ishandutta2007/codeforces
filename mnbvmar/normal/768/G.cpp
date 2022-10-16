#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
} 

template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif


const int MaxN = 1e5 + 6;

int N;
vector<int> adj[MaxN];
int treeSize[MaxN];
multiset<int> subtrees[MaxN];
int result[MaxN];


void dfs(int v, int p) {
  treeSize[v] = 1;
  for (int s : adj[v]) {
    if (s != p) {
      dfs(s, v);
      treeSize[v] += treeSize[s];
    }
  }
}

#define dfs hmmmmmm

void dfsUp(int v, int p) {
  vector<int> children;

  for (int s : adj[v]) {
    if (s == p) { continue; }
    dfsUp(s, v);
    children.push_back(s);
  }

  int maxTree = -1;

  if (SZ(children) > 0) {
    int maxTreeSize = -1, ndMaxTreeSize = -1;
    int minTreeSize = 1e9, minTree = -1;
    for (int s : children) {
      if (treeSize[s] > maxTreeSize) {
        ndMaxTreeSize = maxTreeSize;
        maxTreeSize = treeSize[s];
        maxTree = s;
      } else if (treeSize[s] > ndMaxTreeSize) {
        ndMaxTreeSize = treeSize[s];
      }
      if (treeSize[s] < minTreeSize) {
        minTreeSize = treeSize[s];
        minTree = s;
      }
    }

    int remainder = N - treeSize[v];
    debug(v, minTreeSize, maxTreeSize, remainder);

    if (maxTreeSize == remainder) {
      result[v] = remainder;
    } else if (maxTreeSize > remainder) {
      int left = -1, right = maxTreeSize + 1;
      auto check = [&](int res) {
        if (res < remainder) { return false; }
        if (res < ndMaxTreeSize) { return false; }
        if (res >= remainder && res >= maxTreeSize) { return true; }
        auto it = subtrees[maxTree].lower_bound(maxTreeSize - res);
        if (it == subtrees[maxTree].end()) { return false; }
        int sz = *it;
        if (maxTree != minTree && minTreeSize + sz <= res) { return true; }
        if (remainder > 0 && sz + remainder <= res) { return true; }
        return false;
      };

      while (left < right - 1) {
        int mid = (left + right) / 2;
        if (check(mid)) {
          right = mid;
        } else {
          left = mid;
        }
      }

      debug(v, right);

      result[v] = right;
    }

    subtrees[v].swap(subtrees[maxTree]);
  } else {
    result[v] = N - 1;
  }

  for (int s : children) {
    if (s != maxTree) {
      for (int sz : subtrees[s]) { subtrees[v].insert(sz); }
    }
    subtrees[s].clear();
    subtrees[v].insert(treeSize[s]);
  }

#ifdef LOCAL
  vector<int> X(ALL(subtrees[v]));
  debug(v, X);
#endif
}


multiset<int> allSizes;
multiset<int> ancestors;


void inclTree(int v, int p) {
  allSizes.insert(treeSize[v]);
  for (int s : adj[v]) {
    if (s != p) { inclTree(s, v); }
  }
}

void exclTree(int v, int p) {
  allSizes.erase(allSizes.find(treeSize[v]));
  for (int s : adj[v]) {
    if (s != p) { exclTree(s, v); }
  }
}


void dfsDown(int v, int p) {
  vector<int> children;

  for (int s : adj[v]) {
    if (s == p) { continue; }
    children.push_back(s);
  }

  int maxTree = -1;

  if (SZ(children) > 0) {
    int maxTreeSize = -1;
    int minTreeSize = 1e9, minTree = -1;
    for (int s : children) {
      if (treeSize[s] > maxTreeSize) {
        maxTreeSize = treeSize[s];
        maxTree = s;
      }
      if (treeSize[s] < minTreeSize) {
        minTreeSize = treeSize[s];
        minTree = s;
      }
    }

    int remainder = N - treeSize[v];
    debug(v, remainder, minTreeSize, maxTreeSize);

    if (remainder > maxTreeSize) {
      int left = -1, right = remainder + 1;
      auto check = [&](int res) {
        if (res < maxTreeSize) { return false; }
        if (res >= maxTreeSize && res >= remainder) { return true; }
        auto it = allSizes.lower_bound(remainder - res);
        if (it != allSizes.end()) {
          int sz = *it;
          if (minTreeSize + sz <= res) { return true; }
        }
        auto it2 = ancestors.lower_bound(N - res);
        if (it2 != ancestors.end()) {
          int sz = *it2;
          if (minTreeSize + (sz - treeSize[v]) <= res) { return true; }
        }
        return false;
      };

      while (left < right - 1) {
        int mid = (left + right) / 2;
        if (check(mid)) {
          right = mid;
        } else {
          left = mid;
        }
      }

      result[v] = right;
    }

    for (int s : children) {
      if (s == maxTree) { continue; }
      inclTree(s, v);
    }

    ancestors.insert(treeSize[v]);

    dfsDown(maxTree, v);

    for (int s : children) {
      if (s == maxTree) { continue; }
      exclTree(s, v);
      dfsDown(s, v);
    }

    ancestors.erase(ancestors.find(treeSize[v]));
  }

  allSizes.insert(treeSize[v]);

#ifdef LOCAL
  vector<int> X(ALL(allSizes));
  debug(v, X);
#endif
}


#undef dfs


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  if (N == 1) {
    cout << "0\n";
    return 0;
  }

  for (int i = 0; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, 0);
  dfsUp(0, 0);
  
  for (int i = 1; i <= N; i++) {
    debug(i, result[i]);
  }

  dfsDown(0, 0);

  for (int i = 1; i <= N; i++) {
    cout << result[i] << "\n";
  }
}