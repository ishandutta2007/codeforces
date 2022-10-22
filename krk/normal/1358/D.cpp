#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 600006;

int n;
ll x;
int d[Maxn];
ll res;

ll Sum(ll fir, ll lst) { return (fir + lst) * (lst - fir + 1) / 2ll; }

int main()
{
    scanf("%d %I64d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
        d[n + i] = d[n + n + i] = d[i];
    }
    n *= 3;
    ll lft = x;
    int rig = -1;
    ll cur = 0ll;
    for (int i = 0; i < n; i++) {
        if (rig < i) {
            rig = i;
            lft = x;
            cur = 0ll;
        }
        while (rig < n && d[rig] <= lft) {
            cur += Sum(1, d[rig]);
            lft -= d[rig++];
        }
        ll cand = cur;
        if (rig < n && lft > 0) cand += Sum(1, lft);
        res = max(res, cand);
        cur -= Sum(1, d[i]);
        lft += d[i];
    }
    int lef = n;
    for (int i = n - 1; i >= 0; i--) {
        if (lef > i) {
            lef = i;
            lft = x;
            cur = 0ll;
        }
        while (lef >= 0 && d[lef] <= lft) {
            cur += Sum(1, d[lef]);
            lft -= d[lef--];
        }
        ll cand = cur;
        if (lef >= 0 && lft > 0) cand += Sum(d[lef] - lft + 1, d[lef]);
        res = max(res, cand);
        cur -= Sum(1, d[i]);
        lft += d[i];
    }
    cout << res << endl;
    return 0;
}