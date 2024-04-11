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

const int N = 200005;

int t, n;
int price[N], score[N], x, a, y, b;
int tab[N];
long long k;

bool good(int w) {
    for (int i = 1; i <= n; i++) {
        score[i] = 0;
        tab[i] = i;
    }
    for (int i = 1; i <= w; i++) {
        if (i % a == 0) {
            score[i] += x;
        }
        if (i % b == 0) {
            score[i] += y;
        }
    }
    sort(tab + 1, tab + 1 + n, [](int a, int b) { return score[a] < score[b]; });
    long long sum = 0;
    int cnt = 1;
    for (int i = n; i >= 1 && cnt <= w; i--) {
        sum += price[i] * (long long)score[tab[i]] / 100;
        if (sum >= k) return true;
        cnt++;
    }
    return false;
}

void test() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &price[i]);
    }
    sort(price + 1, price + 1 + n);
    scanf("%d %d", &x, &a);
    scanf("%d %d", &y, &b);
    scanf("%lld", &k);
    int low = 1;
    int high = n;
    int res = n + 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (good(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (res == n + 1) {
        printf("-1\n"); 
    } else {
        printf("%d\n", res);
    }
}

int main() {
    
    scanf("%d", &t);
    
    while (t--) {
        test();
    }
    
    return 0;
}