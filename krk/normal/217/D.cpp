#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<120> bmask;

const int Maxb = 62;
const int Mod = 1000000007;

int n, mod, t;
int to;
int cnt[Maxb];
int slen;
bmask has[Maxb];
int ways[Maxb];
int res;

bmask Left(bmask mask, int hm)
{
    int lft = mod - hm;
    bmask tmp = mask;
    tmp <<= lft;
    mask >>= hm;
    mask |= tmp;
    return mask;
}

bmask Right(const bmask &mask, int hm)
{
    return Left(mask, mod - hm);
}

void Gen(int lvl)
{
    while (lvl <= to && has[slen][lvl]) lvl++;
    if (lvl > to) res = (res + ways[slen]) % Mod;
    else if (lvl == to) {
        res = (res + ways[slen]) % Mod;
        if (!has[slen][lvl])
            res = (res + ll(ways[slen]) * cnt[lvl]) % Mod;
    } else {
        slen++;
        has[slen] = has[slen - 1];
        ways[slen] = ways[slen - 1];
        Gen(lvl + 1);
        has[slen] |= Left(has[slen - 1], lvl);
        has[slen] |= Right(has[slen - 1], lvl);
        ways[slen] = ll(ways[slen - 1]) * cnt[lvl] % Mod;
        Gen(lvl + 1);
        slen--;
    }
}

int main()
{
    scanf("%d %d %d", &n, &mod, &t);
    while (t--) {
        int x; scanf("%d", &x);
        x %= mod;
        if (mod - x < x) x = mod - x;
        cnt[x]++;
    }
    to = mod / 2;
    has[slen][0] = 1;
    ways[slen] = 1;
    Gen(1);
    cout << res << endl;
    return 0;
}