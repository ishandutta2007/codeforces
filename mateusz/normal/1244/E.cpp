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

int n, A[N];
long long k;
long long pref[N];

long long ans;

void solve() {
    for (int i = 1; i <= n; i++) {
        long long currentCost = (long long)A[i] * i - pref[i];
        if (currentCost > k) {
            break;
        }
        long long rest = k - currentCost;
        int low = i;
        int high = n;
        int res = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long addCost = (pref[n] - pref[mid]) - (long long)(n - mid) * (A[mid]);
            if (addCost <= rest) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        ans = min(ans, (long long)A[res] - A[i]);
        
        if (res == i) {
            continue;
        }
        
        low = A[res - 1];
        high = A[res];
        while (low <= high) {
            int mid = (low + high) / 2;
            long long addCost = (pref[n] - pref[res - 1]) - (long long)(n - res + 1) * mid;
            if (addCost <= rest) {
                ans = min(ans, (long long)mid - A[i]);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
}

int main() {
    
    scanf("%d %lld", &n, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    sort(A + 1, A + 1 + n);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + A[i];
    }
    
    ans = 1e9 + 5;
    
    solve();
    reverse(A + 1, A + 1 + n);
    for (int i = 1; i <= n; i++) {
        A[i] = 1e9 - A[i];
    }
    
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + A[i];
    }
    solve();
    
    printf("%lld\n", ans);
    
    return 0;
}