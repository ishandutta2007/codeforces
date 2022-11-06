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

const int N = 200005;

int n;
int p[N];
bool vis[N];

vector<pair<int, int>> ans;

void merge(vector<int> A, vector<int> B) {
    ans.push_back({A.back(), B.back()});
    for (int i = 0; i + 1 < A.size(); i++) {
        ans.push_back({A[i], B.back()});
    }
    for (int i = 0; i + 1 < B.size(); i++) {
        ans.push_back({B[i], A.back()});
    }
    ans.push_back({A.back(), B.back()});
}

void oneCycle(vector<int> A) {
    ans.push_back({A[0], A[1]});
    ans.push_back({A[1], A[2]});
    ans.push_back({A[0], A[2]});
    for (int i = 3; i < A.size(); i++) {
        ans.push_back({A[1], A[i]});
    }
    ans.push_back({A[1], A[0]});
}

vector<vector<int>> findCycles() {
    vector<vector<int>> cycles;
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int w = i;
        vector<int> cycle;
        do {
            cycle.push_back(p[w]);
            w = p[w];
            vis[w] = true;
        } while (w != i);
        cycles.push_back(cycle);
    }
    return cycles;
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    
    vector<vector<int>> cycles = findCycles();
    
    if (cycles.size() == 1) {
        oneCycle(cycles[0]);
    } else {
        for (int i = 0; i + 1 < cycles.size(); i += 2) {
            merge(cycles[i], cycles[i + 1]);
        }
        
        if (cycles.size() % 2 == 1) {
            merge(cycles.back(), {cycles[0][0]});
        }
    }
    
    printf("%d\n", ans.size());
    
    for (auto p : ans) {
        printf("%d %d\n", p.first, p.second);
    }
    
    return 0;
}