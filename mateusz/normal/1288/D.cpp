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

const int N = 300005, M = 9;

int n, m;
int a[N][M];
int cnt[1 << M];

int main() {
    
    scanf("%d %d", &n, &m);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            mx = max(mx, a[i][j]);
        }
    }
    
    int low = 0;
    int high = mx;
    int res = low;
    int resA = -1;
    int resB = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        bool good = false;
        
        for (int i = 0; i < (1 << m); i++) {
            cnt[i] = 0;
        }
        
        for (int i = 1; i <= n; i++) {
            int mask = 0;
            for (int j = 0; j < m; j++) {
                mask *= 2;
                mask += (a[i][j] >= mid);
            }
            cnt[mask] = i;
        }
        
        for (int a = 0; a < (1 << m); a++) {
            for (int b = 0; b < (1 << m); b++) {
                if ((a | b) == (1 << m) - 1 && cnt[a] > 0 && cnt[b] > 0) {
                    good = true;
                    resA = cnt[a];
                    resB = cnt[b];
                    break;
                }
            }
            if (good) {
                break;
            }
        }
        if (good) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    printf("%d %d\n", resA, resB);
    return 0;
}