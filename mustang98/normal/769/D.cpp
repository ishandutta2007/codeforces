#include <bits/stdc++.h>

#define F first
#define S second
#define x1 privet1
#define x2 privet2
#define y1 privet3
#define y2 privet4
#define time privet5
#define left privet6

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 10033, log_n = 32, max_m = 111, mod = 1000000007, inf = 1011111111;
const ld eps = 1e-7;

int n, k, cnt[max_n];
bool kk[max_n * 2];

bool is_k(int x) {
    int cnt = 0;
    while (x) {
        if (x % 2) cnt++;
        x /= 2;
    }
    return cnt == k;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("substr.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }
    //cout << cnt[1] << " " << cnt[2] << endl;
    if (k == 0) {
        ll ans = 0;
        for (int i =0 ; i < max_n; ++i) {
            ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < max_n * 2; ++i) {
        kk[i] = is_k(i);
    }
    ll ans = 0;
    for (int i = 0; i < max_n; ++i) {
        for (int q = i + 1; q < max_n; ++q) {
            if (kk[i ^ q]) {
                ans += 1LL * cnt[i] * cnt[q];
            }
        }
    }
    cout << ans << endl;
    return 0;
}