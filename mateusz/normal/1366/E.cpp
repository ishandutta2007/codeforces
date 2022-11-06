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

const int N = 200005, M = 998244353;

int n, m;
int A[N], B[N];
map<int, int> last;
int leftLower[N], rightLower[N];

int mul(int w, int u) {
    return (long long)w * u % M;
}
int main() {
    
    scanf("%d %d", &n, &m);
    
    vector<int> sta;
    sta.push_back(0);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        last[A[i]] = i;
        while (A[sta.back()] >= A[i]) sta.pop_back();
        leftLower[i] = sta.back();
        sta.push_back(i);
    }
    
    sta.clear();
    sta.push_back(n + 1);
    for (int i = n; i >= 1; i--) {
        while (A[sta.back()] >= A[i]) sta.pop_back();
        rightLower[i] = sta.back();
        sta.push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &B[i]);
        if (!last.count(B[i])) {
            printf("0\n");
            return 0;
        }
    }
    
    int ans = 1;
    if (leftLower[last[B[1]]] != 0 || rightLower[last[B[m]]] != n + 1) {
        printf("0\n");
        return 0;
    }
    for (int i = 2; i <= m; i++) {
        int w = last[B[i]];
        int u = last[B[i - 1]];
        int from = max(u + 1, leftLower[w] + 1);
        int to = min(w, rightLower[u]);
        ans = mul(ans, to - from + 1);
    }
    printf("%d\n", ans);
    
    return 0;
}