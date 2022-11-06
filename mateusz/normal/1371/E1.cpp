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
int n, p;
int A[N];

int main() {
    
    scanf("%d %d", &n, &p);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        mx = max(A[i], mx);
    }
    sort(A + 1, A + 1 + n);
    for (int i = 1; i <= n; i++) {
        A[i] -= n;
    }
    
    sort(A + 1, A + 1 + n);
    reverse(A + 1, A + 1 + n);
    vector<int> ans;
    for (int i = mx; ; i--) {
        int res = 1;
        bool brk = false;
        for (int j = 1; j <= n; j++) {
            if ((i - A[j] + 1 - j) == 0) {
                brk = true;
                break;
            }
            res = (long long)res * min(n - j + 1, (i - A[j] + 1 - j)) % p;
//             A[j]--;
        }
        if (brk) break;
        if (res != 0) {
            ans.push_back(i);
        }
    }
    
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto x : ans) {
        printf("%d ", x);
    }
    printf("\n");
    
    return 0;
}