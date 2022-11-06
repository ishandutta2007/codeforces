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
int A[N], B[N];
int main() {
    
    scanf("%d", &n);
    set<int> myNumbers;
    map<int, int> last;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        last[A[i]] = i;
        myNumbers.insert(A[i]);
    }
    set<int> remaining;
    for (int i = 0; i <= 200000; i++) {
        if (!myNumbers.count(i)) remaining.insert(i);
    }
    
    for (int i = 1; i <= n; i++) {
        B[i] = *remaining.begin();
        remaining.erase(remaining.begin());
        if (*remaining.begin() < A[i]) {
            printf("-1\n");
            return 0;
        }
        if (last[A[i]] == i) {
            remaining.insert(A[i]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
    
    return 0;
}