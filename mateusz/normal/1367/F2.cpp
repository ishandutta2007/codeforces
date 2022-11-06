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
int n, k;
int A[N], B[N];
int dp[N];
int prevPos[N];
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        map<int, vector<int>> ids;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            ids[A[i]].push_back(i);
        }
        int last = -1;
        ids[last].push_back(0);
        map<int, int> prevVal;
        for (auto p : ids) {
            int val = p.first;
            auto poses = p.second;
            prevVal[val] = last;
            prevPos[poses[0]] = ids[last].back();
            for (int i = 1; i < poses.size(); i++) {
                prevPos[poses[i]] = poses[i - 1];
            }
            last = val;
        }
        
        int ans = 0;
        map<int, int> cntOcc, lastOcc;
        lastOcc[-1] = 0;
        for (int i = 1; i <= n; i++) {
            if (prevPos[i] < i) {
                dp[i] = dp[prevPos[i]] + 1;
            } else {
                dp[i] = cntOcc[prevVal[A[i]]] + 1;
            }
            lastOcc[A[i]] = i;
            cntOcc[A[i]]++;
            if (lastOcc.count(prevVal[A[i]])) {
                if (lastOcc[prevVal[A[i]]] == ids[prevVal[A[i]]].back()) {
                    ans = max(ans, (int)ids[A[i]].size() - cntOcc[A[i]] + 1 + dp[lastOcc[prevVal[A[i]]]]);
                } else {
                    ans = max(ans, (int)ids[A[i]].size() - cntOcc[A[i]] + 1 + cntOcc[prevVal[A[i]]]);
                }
            }
            ans = max(ans, dp[i]);
        }
        printf("%d\n", n - ans);
        
    }
    
    return 0;
}