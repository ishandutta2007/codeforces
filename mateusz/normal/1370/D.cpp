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
int A[N];

bool goodEven(int w) {
    int current = 1;
    int size = 0;
    for (int i = 1; i <= n; i++) {
        if (size == k) break;
        if (current == 1) {
            current = 0;
            size++;
            continue;
        } else if (A[i] <= w) {
            current = 1;
            size++;
        }
    }
    return size == k;
}

bool goodOdd(int w) {
    int current = 1;
    int size = 0;
    for (int i = 1; i <= n; i++) {
        if (size == k) break;
        if (current == 0) {
            current = 1;
            size++;
            continue;
        } else if (A[i] <= w) {
            current = 0;
            size++;
        }
    }
    return size == k;
}

bool good(int w) {
    return goodEven(w) || goodOdd(w);
}

int main() {
    
    scanf("%d %d", &n, &k);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        mx = max(mx, A[i]);
    }
    
    int low = 1;
    int high = mx;
    int res = mx;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (good(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}