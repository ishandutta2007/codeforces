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

int n;
long long a[N];
int b[N], t[N];
bool good[N];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        t[i] = i;
    }
    
    sort(t + 1, t + 1 + n, cmp);
    
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
        int w = t[i];
        if (i < n && a[w] == a[t[i + 1]]) {
            good[w] = true;
            ans += b[w];
            continue;
        }
        if (i > 1 && a[w] == a[t[i - 1]]) {
            good[w] = true;
            ans += b[w];
            continue;
        }
        for (int j = i + 1; j <= n; j++) {
            int u = t[j];
            if ((a[w] & a[u]) == a[w] && good[u] == true) {
                good[w] = true;
                ans += b[w];
                break;
            }
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}