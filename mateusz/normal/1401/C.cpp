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

int n;
int A[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int mini = 1e9;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            mini = min(mini, A[i]);
        }
        vector<int> divisible;
        for (int i = 1; i <= n; i++) {
            if (A[i] % mini == 0) {
                divisible.push_back(A[i]);
            }
        }
        sort(divisible.begin(), divisible.end());
        int ptr = 0;
        for (int i = 1; i <= n; i++) {
            if (ptr == divisible.size()) {
                break;
            }
            if (A[i] % mini == 0) {
                A[i] = divisible[ptr++];
            }
        }
        bool sorted = true;
        for (int i = 2; i <= n; i++) {
            if (A[i] < A[i - 1]) {
                sorted = false;
                break;
            }
        }
        printf(sorted ? "YES\n" : "NO\n");
    }
    
    return 0;
}