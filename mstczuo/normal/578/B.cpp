# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int a[65536*8];

typedef pair<long long,long long> pll;

int n, k, x, M;

long long ans = 0;

int get(int l,int r) {
    if(l > r) return 0;
    int ret = 0;
    for(int s = M + l - 1, t = M + r + 1; s^t^1; s = s >> 1, t = t >> 1) {
        if (~s&1) ret |= a[s^1];
        if ( t&1) ret |= a[t^1];
    }
    return ret;
}

int main() {
    cin >> n >> k >> x;
    for(M = 1; M < n + 2; M = M << 1);
    for(int i = 1; i <= n; ++i) cin >> a[M + i];
    for(int i = M - 1; i; --i) a[i] = a[i<<1]|a[i<<1|1];
    for(int i = 1; i <= n; ++i) {
        long long t = a[M + i];
        for(int j = 0; j < k; ++j) t *= x;
        ans = max(ans, get(1, i - 1) | get(i + 1, n) | t);
    }
    cout << ans << endl;
}