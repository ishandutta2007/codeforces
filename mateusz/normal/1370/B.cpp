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
int n, x;
int A[N];
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> even, odd;
        for (int i = 1; i <= 2 * n; i++) {
            scanf("%d", &A[i]);
            if (A[i] % 2 == 0) even.push_back(i);
            else odd.push_back(i);
        }
        
        if (odd.size() % 2 == 1) {
            odd.pop_back();
            even.pop_back();
        } else {
            if (even.size() >= 2) {
                even.pop_back();
                even.pop_back();
            } else {
                odd.pop_back();
                odd.pop_back();
            }
        }
        
        for (int i = 0; i < even.size(); i += 2) {
            printf("%d %d\n", even[i], even[i + 1]);
        }
        for (int i = 0; i < odd.size(); i += 2) {
            printf("%d %d\n", odd[i], odd[i + 1]);
        }
    }
    
    return 0;
}