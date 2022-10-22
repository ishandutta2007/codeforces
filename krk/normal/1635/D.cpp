#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int mod = 1000000007;
const int lim = 2000000000;

int f[Maxn];
int sum[Maxn];
int n, p;
set <int> S;
int res;

int Digs(int num)
{
    int res = 0;
    while (num) {
        res++;
        num /= 2;
    }
    return res;
}

bool Remove(int x)
{
    if (x == 0) return false;
    auto it = S.find(x);
    if (it != S.end()) return true;
    if (x & 1) return Remove(x / 2);
    else if (x & 2) return false;
    else return Remove(x / 4);
}

int main()
{
    scanf("%d %d", &n, &p);
    f[0] = 1;
    for (int i = 1; i <= p; i++) {
        f[i] = f[i - 1];
        if (i >= 2) f[i] = (f[i] + f[i - 2]) % mod;
    }
    for (int i = 0; i <= p; i++) {
        sum[i] = f[i];
        if (i) sum[i] = (sum[i] + sum[i - 1]) % mod;
    }
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        //int a = i + 1;
        S.insert(a);
    }
    while (!S.empty()) {
        auto it = S.end(); it--;
        int num = *it; S.erase(it);
        int digs = Digs(num);
        if (digs > p) continue;
        if (!Remove(num))
            res = (res + sum[p - digs]) % mod;
    }
    printf("%d\n", res);
    return 0;
}