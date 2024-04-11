#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 3005;

int n;
ll k;
int a[Maxn];
int rl[Maxn];
int notknown;
ll mn[Maxn], mx[Maxn];

ll Get()
{
    ll cur = 0;
    ll mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cur += rl[i];
        mn = min(mn, cur);
        mx = max(mx, cur);
    }
    return mx - mn + 1;
}

void Write(int lef, int rig, int val)
{
    for (int i = lef; i <= rig; i++) if (a[i] == 0)
        rl[i] = val;
}

ll getMax()
{
    ll cur = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) cur += a[i];
        else {
            rl[i] = min(k, -(mn[i + 1] + cur));
            if (rl[i] < k) {
                Write(i + 1, n - 1, -k);
                res = max(res, Get());
                return res;
            }
            cur += rl[i];
        }
        ll cur2 = cur;
        for (int j = i + 1; j <= n; j++) {
            if (a[j]) cur2 += a[j];
            else {
                rl[j] = max(-k, -(mx[j + 1] + cur2));
                cur2 += rl[j];
            }
            res = max(res, max(0ll, cur) - min(0ll, cur2) + 1ll);
        }
    }
    return res;
}

ll getMin()
{
    ll cur = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) cur += a[i];
        else {
            rl[i] = max(-k, -(mx[i + 1] + cur));
            if (rl[i] > -k) {
                Write(i + 1, n - 1, k);
                res = max(res, Get());
                return res;
            }
            cur += rl[i];
        }
        ll cur2 = cur;
        for (int j = i + 1; j <= n; j++) {
            if (a[j]) cur2 += a[j];
            else {
                rl[j] = min(k, -(mn[j + 1] + cur2));
                cur2 += rl[j];
            }
            res = max(res, max(0ll, cur2) - min(0ll, cur) + 1ll);
        }
    }
    return res;
}

int main()
{
    scanf("%d %I64d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        rl[i] = a[i];
    }
    mn[n] = mx[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        if (a[i]) {
            mn[i] = a[i] + mn[i + 1];
            mx[i] = a[i] + mx[i + 1];
        } else {
            mn[i] = -k + mn[i + 1];
            mx[i] = k + mx[i + 1];
        }
    if (mn[0] > 0 || mx[0] < 0) { printf("-1\n"); return 0; }
    cout << max(getMin(), getMax()) << endl;
    return 0;
}