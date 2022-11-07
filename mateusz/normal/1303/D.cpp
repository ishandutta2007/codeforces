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

long long n;
int m;
int cnt[105], occurs[105];
int a[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %d", &n, &m);
        for (int i = 0; i < 60; i++) {
            cnt[i] = occurs[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &a[i]);
            int w = a[i];
            for (int j = 0; j < 30; j++) {
                if (w % 2) {
                    cnt[j]++;
                    break;
                }
                w /= 2;
            }
        }
        
        long long w = n;
        for (int i = 0; i < 60; i++) {
            if (w % 2) {
                occurs[i] = 1;
            }
            w /= 2;
        }
        
        int last = -1;
        int ans = 0;
        for (int i = 0; i < 60; i++) {
            if (cnt[i] > 0 && last != -1) {
                ans += i - last;
                cnt[i]--;
                last = -1;
            }
            if (occurs[i] > 0) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                } else {
                    if (last == -1) {
                        last = i;
                    }
                }
            }
            cnt[i + 1] += cnt[i] / 2;
        }
        if (last != -1) {
            printf("-1\n");
        } else {
            printf("%d\n", ans);
        }
    }
    
    return 0;
}