#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxp = 317000;

ll n, l, r, k;
ll res = -1;

void Solve1(ll lef, ll rig, ll k)
{
    for (ll i = lef; i <= rig && n + i <= k; i++)
        if (k % (n + i) == 0)
            res = max(res, ll(i));
}

void Solve2(ll lef, ll rig, ll k)
{
    for (ll z = 1; z * n <= k; z++)
        if (k % z == 0) {
            ll got = k / z - n;
            if (lef <= got && got <= rig)
                res = max(res, got);
        }
}

void Solve3(ll lef1, ll rig1, ll lef2, ll rig2, ll k)
{
    for (ll add = 0; add <= n; add++) {
        ll lftx = k % (n + add) - r;
        if (lftx < 0) lftx += n + add;
        ll lfty = add - lftx;
        if (lef1 <= lftx && lftx <= rig1 &&
            lef2 <= lfty && lfty <= rig2)
            res = max(res, add);
    }
}

void Solve4(ll lef1, ll rig1, ll lef2, ll rig2, ll k)
{
    if (lef1 <= k - r && k - r <= rig1) res = max(res, k - r + rig2);
    for (ll z = 1; z * n <= k; z++) {
        ll myk = k - z * n - r;
        if (myk < 0) continue;
        ll all = myk / z;
        ll x = myk % z;
        ll y = all - x;
        if (x < lef1) {
            x += z;
            y -= (z + 1);
        }
        if (y > rig2) {
            ll tk = (y - rig2) / (z + 1);
            y -= tk * (z + 1);
            x += tk * z;
            if (y > rig2) {
                y -= (z + 1);
                x += z;
            }
        }
        if (lef1 <= x && x <= rig1 && lef2 <= y && y <= rig2)
            res = max(res, x + y);
    }
}

int main()
{
    cin >> n >> l >> r >> k;
    ll delt = l - 1;
    l = 1;
    r -= delt;
    if (r <= 0) r += n;
    if (r == n)
        if (n <= Maxp) {
            Solve1(0, n, k);
            Solve1(1, n, k + 1);
        } else {
            Solve2(0, n, k);
            Solve2(1, n, k + 1);
        }
    else if (n <= Maxp) {
        Solve3(0, r, 0, n - r, k);
        Solve3(1, r, 0, n - r, k + 1);
    } else {
        Solve4(0, r, 0, n - r, k);
        Solve4(1, r, 0, n - r, k + 1);
    }
    cout << res << endl;
    return 0;
}