#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int cnt[max_n];

int h[max_n];
int n;
int cnt_f[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    ll k;
    cin >> n >> k;
    int minn = inf;
    for (int i = 0; i < n; ++i) {
        scanf("%d", h + i);
        cnt_f[h[i]]++;
        minn = min(minn, h[i]);
    }
    int c = n;
    for (int i = 1; i < max_n; ++i) {
        cnt[i] = c;
        c -= cnt_f[i];
    }
    int ans = 0;
    ll cur = 0;
    for (int i = max_n - 1; i > minn; --i) {
        if (cur + cnt[i] > k) {
            ans++;
            cur = cnt[i];
        } else {
            cur += cnt[i];
        }
    }
    if (cur) {
        ++ans;
    }
    cout << ans;

    return 0;
}