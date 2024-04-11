#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int Maxn = 300005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
int q;
int n;
int a[Maxn];
int S[Maxn], slen;
ii cur;
ii seq1[Maxn], seq2[Maxn];
int len1, len2;
ll res;

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

void Clear()
{
    slen = 0;
    cur = ii(0, 0);
}

void Give(int a)
{
    if (slen == 0 || S[slen - 1] != a) {
        cur.first = (ll(cur.first) + ll(pw1[slen]) * a) % mod1;
        cur.second = (ll(cur.second) + ll(pw2[slen]) * a) % mod2;
        S[slen++] = a;
    } else {
        slen--;
        cur.first = (ll(cur.first) - ll(pw1[slen]) * a % mod1 + mod1) % mod1;
        cur.second = (ll(cur.second) - ll(pw2[slen]) * a % mod2 + mod2) % mod2;
    }
}

void Solve(int l, int r)
{
    if (l >= r) return;
    int m = l + r >> 1;
    Solve(l, m); Solve(m + 1, r);
    Clear();
    len1 = 0;
    for (int i = m; i >= l; i--) {
        Give(a[i]);
        seq1[len1++] = cur;
    }
    Clear();
    len2 = 0;
    for (int i = m + 1; i <= r; i++) {
        Give(a[i]);
        seq2[len2++] = cur;
    }
    sort(seq1, seq1 + len1);
    sort(seq2, seq2 + len2);
    int a = 0, b = 0;
    while (a < len1 && b < len2)
        if (seq1[a] < seq2[b]) a++;
        else if (seq1[a] > seq2[b]) b++;
        else {
            int c = a;
            while (c < len1 && seq1[a] == seq1[c]) c++;
            int d = b;
            while (d < len2 && seq2[b] == seq2[d]) d++;
            res += ll(c - a) * (d - b);
            a = c; b = d;
        }
}

int main()
{
    arg1 = uniform_int_distribution<int>(2000000, 200000000)(rng);
    arg2 = uniform_int_distribution<int>(2000000, 200000000)(rng);
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        res = 0;
        Solve(0, n - 1);
        printf("%I64d\n", res);
    }
    return 0;
}