#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
const int Maxm = 10000005;
const int mod = 1000000007;

int n;
int a[Maxn];
int pw2[Maxn], ways[Maxn];
int mx[Maxm];
int cnt[Maxm];
int val[Maxm];
int all;
int seq[Maxn], slen;
int res;

void Gen(int lvl, int cur, int add)
{
    if (lvl >= slen) {
        if (cur != 1) {
            int got = ways[cnt[cur]];
            if (add == -1) got = (mod - got) % mod;
            res = (res + got) % mod;
        } 
    } else {
        Gen(lvl + 1, cur, add);
        Gen(lvl + 1, cur * seq[lvl], -add);
    }
}

int main()
{
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw2[i] = pw2[i - 1] * 2ll % mod;
        ways[i] = (pw2[i] - 1 + mod) % mod;
    }
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for (int i = 2; i < Maxm; i++) if (mx[i] == 0)
        for (int j = i; j < Maxm; j += i)
            mx[j] = i;
    for (int i = 1; i < Maxm; i++)
        for (int j = i + i; j < Maxm; j += i)
            cnt[i] += cnt[j];
    for (int i = Maxm - 1; i > 1; i--) {
        val[i] = ways[cnt[i]];
        for (int j = i + i; j < Maxm; j += i)
            val[i] = (val[i] - val[j] + mod) % mod;
        all = (all + val[i]) % mod;
    }
    for (int i = 0; i < n; i++) {
        int num = a[i];
        slen = 0;
        while (num > 1) {
            int cur = mx[num];
            seq[slen++] = cur;
            while (mx[num] == cur)
                num /= cur;
        }
        res = (res + all) % mod;
        Gen(0, 1, 1);
    }
    printf("%d\n", res);
    return 0;
}