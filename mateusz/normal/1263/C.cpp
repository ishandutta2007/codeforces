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
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 100005;

bool find(int w, int n) {
    int low = 1;
    int high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (n / mid == w) {
            return true;
        }
        if (n / mid > w) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        set<int> values;
        values.insert(0);
        for (int i = 1; i * i <= n; i++) {
            values.insert(n / i);
            if (find(i, n)) {
                values.insert(i);
            }
        }
        
        printf("%d\n", values.size());
        for (int x : values) {
            printf("%d ", x);
        }
        printf("\n");
    }
    
    return 0;
}