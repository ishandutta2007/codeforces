#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 400111, max_val = 10000111, inf = 1000111222;

int cnt[2 * max_val];
int m[max_n];
int n;

ll calc00(int tr) {
    for (int i = 0; i <= tr; ++i) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (m[i] & tr) continue;
        cnt[m[i] & (tr - 1)]++;
    }
    for (int i = tr - 1; i >= 0; --i) {
        cnt[i] += cnt[i + 1];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (m[i] & tr) continue;
        int cur = m[i] & (tr - 1);
        ans += cnt[tr - cur];
        if (cur * 2 >= tr) {
            --ans;
        }
    }
    if (ans % 2) exit(228);
    return ans / 2;
}

ll calc11(int tr) {
    for (int i = 0; i <= tr; ++i) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if ((m[i] & tr) == 0) continue;
        cnt[m[i] & (tr - 1)]++;
    }
    for (int i = tr - 1; i >= 0; --i) {
        cnt[i] += cnt[i + 1];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((m[i] & tr) == 0) continue;
        int cur = m[i] & (tr - 1);
        ans += cnt[tr - cur];
        if (cur * 2 >= tr) {
            --ans;
        }
    }
    if (ans % 2) exit(228);
    return ans / 2;
}


ll calc10(int tr) {
    for (int i = 0; i <= tr; ++i) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (m[i] & tr) continue;
        cnt[m[i] & (tr - 1)]++;
    }
    for (int i = 1; i < tr; ++i) {
        cnt[i] += cnt[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((m[i] & tr) == 0) continue;
        int cur = m[i] & (tr - 1);
        ans += cnt[tr - 1 - cur];

    }
    return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    //n = 400000;
    for (int i = 0; i < n; ++i) {
        //m[i] = gen() % max_val;
        scanf("%d", m + i);
    }
    sort(m, m + n);
    int ans = 0;
    for (int bit = 0; (1 << bit) < 2 * max_val; ++bit) {
        int tr = (1 << bit);
        ll sum = calc00(tr) + calc10(tr) + calc11(tr);
        if (sum % 2) {
            ans |= tr;
        }
    }
    cout << ans << endl;
    return 0;
}