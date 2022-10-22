#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;

int pw10[Maxn], inv9;
string s;
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int main()
{
    pw10[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw10[i] = ll(pw10[i - 1]) * 10ll % mod;
    inv9 = Inv(9);
    cin >> s;
    int cur = 0;
    for (int i = 0; i < s.length(); i++) {
        cur = (10ll * cur + ll(s[i] - '0')) % mod;
        res = (res + ll(pw10[int(s.length()) - i - 1] - 1ll + mod) % mod * ll(inv9) % mod * cur) % mod;
    }
    cur = 0;
    for (int i = int(s.length()) - 1; i >= 0; i--) {
        cur = (cur + ll(pw10[int(s.length()) - 1 - i]) * ll(s[i] - '0')) % mod;
        res = (res + ll(cur) * i) % mod;
    }
    printf("%d\n", res);
    return 0;
}