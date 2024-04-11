#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int mod = 1000000007;
const int Maxn = 1000;

int T;
ll lef1, dif1, rig1;
ll lef2, dif2, rig2;
iii seq[Maxn];
int slen;
int res;
bool bad;

void Add(int x)
{
    if (lef2 - dif2 < lef1 || rig2 + dif2 > rig1) bad = true;
    else res = (res + ll(dif2 / x) * (dif2 / x)) % mod;
}

void Gen(int lvl, int cur)
{
    if (lvl >= slen) Add(cur);
    else {
        for (int i = 0; i < seq[lvl].second.first; i++)
            cur *= seq[lvl].first;
        for (int i = seq[lvl].second.first; i <= seq[lvl].second.second; i++) {
            Gen(lvl + 1, cur);
            cur *= seq[lvl].first;
        }
    }
}

int Solve()
{
    if (dif2 % dif1 || lef2 < lef1 || rig1 < rig2 || (lef2 - lef1) % dif1) return 0;
    slen = 0;
    ll num1 = dif1, num2 = dif2;
    for (int i = 2; i * i <= num2; i++) if (num2 % i == 0) {
        int cnt2 = 0;
        while (num2 % i == 0) { num2 /= i; cnt2++; }
        int cnt1 = 0;
        while (num1 % i == 0) { num1 /= i; cnt1++; }
        if (cnt1 == cnt2) seq[slen++] = iii(i, ii(0, cnt1));
        else seq[slen++] = iii(i, ii(cnt2, cnt2));
    }
    if (num2 > 1) {
        int cnt2 = 1;
        int cnt1 = 0;
        while (num1 % num2 == 0) { num1 /= num2; cnt1++; }
        if (cnt1 == cnt2) seq[slen++] = iii(num2, ii(0, cnt1));
        else seq[slen++] = iii(num2, ii(cnt2, cnt2));
    }
    res = 0; bad = false;
    Gen(0, 1);
    if (bad) return -1;
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d %I64d", &lef1, &dif1, &rig1);
        rig1 = lef1 + dif1 * (rig1 - 1ll);
        scanf("%I64d %I64d %I64d", &lef2, &dif2, &rig2);
        rig2 = lef2 + dif2 * (rig2 - 1ll);
        printf("%d\n", Solve());
    }
    return 0;
}