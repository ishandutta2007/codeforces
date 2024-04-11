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

int n, a[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        priority_queue<pair<int, int> > Q;
        Q.push({n, -1});
        for (int i = 1; i <= n; i++) {
            int from = -Q.top().second;
            int to = from + Q.top().first - 1;
            Q.pop();
            
            int mid = (to - from + 1) % 2 ? (from + to) / 2 : (from + to - 1) / 2;
            a[mid] = i;
            if (mid - 1 - from + 1 >= 1) {
                Q.push({mid - 1 - from + 1, -from});
            }
            if (to - mid >= 1) {
                Q.push({to - mid, -(mid + 1)});
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    
    return 0;
}