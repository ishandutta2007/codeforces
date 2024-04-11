#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;

int n;
int c[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < n; i += 2) {
        ll st = 0, mn = -1;
        for (int j = i + 1; j < n; j++)
            if (j % 2) {
                ll l = 0, r = 0, curst = st;
                if (mn < -1) { l -= (mn + 1); curst -= (mn + 1); }
                if (curst < 0) { l -= curst; curst = 0; }
                if (curst > 0) { r += curst; curst = 0; }
                res += max(0ll, min(c[i] - l, c[j] - r));
                st -= c[j];
                mn = min(mn, st);
            } else st += c[j];
    }
    cout << res << endl;
    return 0;
}