#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, k;
string res;

int Digs(ll cur)
{
    int res = 0;
    while (cur) {
        res += cur % 10;
        cur /= 10;
    }
    return res;
}

void Check(ll cur, bool zer)
{
    int lft = n;
    for (int i = 0; i <= k && lft >= 0; i++)
        lft -= Digs(cur + i);
    if (lft < 0 || lft % (k + 1)) return;
    lft /= (k + 1);
    stringstream ss; ss << cur;
    string cand; ss >> cand;
    if (lft && zer) cand = "0" + cand;
    while (lft >= 10) {
        cand = "9" + cand;
        lft -= 9;
    }
    if (lft > 0)
        cand = string(1, '0' + lft) + cand;
    if (res.length() == 0 || cand.length() < res.length() || cand.length() == res.length() && cand < res)
        res = cand;
}

void Gen(int lvl, ll cur, bool zer)
{
    for (int i = 0; i < 10; i++)
        Check(cur * 10ll + i, zer);
    if (lvl < 16)
        Gen(lvl + 1, cur * 10ll + 9ll, zer);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        res = "";
        for (int i = 0; i + k <= 9; i++)
            Check(i, false);
        for (int i = 0; i < 9; i++)
            Gen(0, i, i == 0);
        if (res.length() == 0) printf("-1\n");
        else printf("%s\n", res.c_str());
    }
    return 0;
}