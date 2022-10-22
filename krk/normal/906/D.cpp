#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Inf = 1000000000;

int n, m;
int a[Maxn];
vector <int> seq;

int phi(int n)
{
    int val = n;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) {
        val -= val / i;
        while (n % i == 0)
            n /= i;
    }
    if (n > 1)
        val -= val / n;
    return val;
}

int toPower(int a, int p, int mod)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

bool smallEnough(int a, int p, int &res)
{
    if (a == 1) { res = 1; return true; }
    res = 1;
    for (int i = 0; i < p; i++)
        if (res <= Inf / a) res *= a;
        else return false;
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    seq.push_back(m);
    while (seq.back() != 1) {
        int nxt = phi(seq.back());
        seq.push_back(nxt);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int q; scanf("%d", &q);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        int i = min(r - l, int(seq.size()) - 1);
        bool small = true;
        int cur = 1;
        int from = min(r, l + i + 5);
        while (from - l > i && small) {
            int res;
            if (smallEnough(a[from], cur, res))
                cur = res;
            else small = false;
            from--;
        }
        while (i >= 0) {
            if (small) {
                int res;
                if (smallEnough(a[l + i], cur, res))
                    cur = res;
                else {
                    small = false;
                    cur = toPower(a[l + i], cur, seq[i]) + seq[i];
                }
            } else if (a[l + i] == 1) {
                cur = 1;
                small = true;
            } else cur = toPower(a[l + i], cur, seq[i]) + seq[i];
            i--;
        }
        printf("%d\n", cur % m);
    }
    return 0;
}