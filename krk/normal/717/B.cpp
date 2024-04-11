#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, c0, c1;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

ll getC(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    vector <int> seq;
    for (int i = 0; i < k; i++)
        seq.push_back(n - i);
    for (int i = 2; i <= k; i++) {
        int num = i;
        for (int j = 0; j < seq.size(); j++) {
            int g = gcd(seq[j], num);
            seq[j] /= g; num /= g;
        }
    }
    ll res = 1;
    for (int j = 0; j < seq.size(); j++)
        res *= seq[j];
    return res;
}

ll Get(ll val)
{
    ll cur = 0;
    for (int i = 0; ll(c1) * i <= val && cur < n; i++) {
        int j = (val - ll(c1) * i) / c0;
        ll my = ll(c1) * i + ll(c0) * j;
        cur += getC(i + j, i) * 2;
        if (j > 0 && cur < n) {
            int sub = (my - (val - c1 + 1)) / c0;
            if (sub > 0)
                cur += getC(i + j, i + 1) - getC(i + j - sub, i + 1);
        }
    }
    return cur;
}

ll getReal(ll val)
{
    ll cur = 0;
    for (int i = 0; ll(c1) * i <= val; i++) {
        int j = (val - ll(c1) * i) / c0;
        ll my = ll(c1) * i + ll(c0) * j;
        cur += getC(i + j, i) * 2;
        if (j > 0) {
            int sub = (my - (val - c1 + 1)) / c0;
            if (sub > 0)
                cur += getC(i + j, i + 1) - getC(i + j - sub, i + 1);
        }
    }
    return cur;
}

ll getRes(ll val)
{
    ll res = 0;
    for (int i = 0; ll(c1) * i <= val; i++) {
        int j = (val - ll(c1) * i) / c0;
        ll my = ll(c1) * i + ll(c0) * j;
        ll g = getC(i + j, i);
        res += 2 * g * my + g * (c0 + c1);
        while (j > 0) {
            j--;
            my -= c0;
            if (my >= val - c1 + 1)
                res += getC(i + j, i) * (my + c1);
            else break;
        }
    }
    return res;
}

int main()
{
    scanf("%d %d %d", &n, &c0, &c1);
    if (c0 > c1) swap(c0, c1);
    if (c0 == 0) {
        cout << ll(c1) * (n - 1) << endl;
        return 0;
    }
    ll lef = 0, rig = 3000000000ll;
    while (lef <= rig) {
        ll mid = lef + rig >> 1;
        if (Get(mid) >= n) rig = mid - 1;
        else lef = mid + 1;
    }
    cout << getRes(lef) - (getReal(lef) - n) * (lef + c0 + c1) << endl;
    return 0;
}