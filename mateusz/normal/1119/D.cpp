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

int n, q;
long long l, r;
long long shift[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &shift[i]);
    }
    sort(shift + 1, shift + 1 + n);
    vector<long long> diffs;
    for (int i = 2; i <= n; i++) {
        diffs.push_back(shift[i] - shift[i - 1]);
    }
    sort(diffs.begin(), diffs.end());
    vector<long long> sumPref(n);
    if (n > 1) {
        sumPref[0] = diffs[0];
        for (int i = 1; i < n; i++) {
            sumPref[i] = sumPref[i - 1] + diffs[i];
        }
    }
    
    scanf("%d", &q);
    while (q--) {
        scanf("%lld %lld", &l, &r);
        r -= l;
        int low = 0;
        int high = n - 2;
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (diffs[mid] <= r + 1) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        long long sum = 0;
        if (res != -1) {
            sum = sumPref[res];
        }
        printf("%lld ", sum + (long long)(n - res - 1) * (r + 1));
    }
    printf("\n");
    return 0;
}