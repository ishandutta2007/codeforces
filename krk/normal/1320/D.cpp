#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int Maxn = 200005;
const int Maxm = 1048576;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
int n;
char S[Maxn];

struct node {
    bool st, en;
    int has;
    ii h;
    node() { st = en = false; has = 0; h = ii(0, 0); }
    bool operator==(const node &b) const {
        if (st != b.st) return false;
        if (en != b.en) return false;
        if (has != b.has) return false;
        return h == b.h;
    }
};
node st[Maxm];

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

node Union(const node &a, const node &b)
{
    node c;
    c.has = a.has + b.has;
    c.h.first = (ll(a.h.first) + ll(b.h.first) * pw1[a.has]) % mod1;
    c.h.second = (ll(a.h.second) + ll(b.h.second) * pw2[a.has]) % mod2;
    if (a.has == 0 && b.has == 0) {
        c.st = (a.st ^ b.st);
        c.en = (a.en ^ b.en);
    } else if (a.has == 0) {
        c.st = (a.en ^ b.st);
        c.en = b.en;
    } else if (b.has == 0) {
        c.st = a.st;
        c.en = (a.en ^ b.st);
    } else {
        if (a.en ^ b.st) {
            c.h.first = (c.h.first + pw1[a.has]) % mod1;
            c.h.second = (c.h.second + pw2[a.has]) % mod2;
        }
        c.st = a.st;
        c.en = b.en;
    }
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r)
        if (S[l] == '1') { st[v].st = st[v].en = true; st[v].has = 0; st[v].h = ii(0, 0); }
        else { st[v].st = st[v].en = false; st[v].has = 1; st[v].h = ii(0, 0); }
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

node Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

int main()
{
    arg1 = uniform_int_distribution<int>(500000000, 800000000)(rng);
    arg2 = uniform_int_distribution<int>(500000000, 800000000)(rng);
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%d", &n);
    scanf("%s", S + 1);
    Create(1, 1, n);
    int q; scanf("%d", &q);
    while (q--) {
        int a, b, len; scanf("%d %d %d", &a, &b, &len);
        printf("%s\n", Get(1, 1, n, a, a + len - 1) == Get(1, 1, n, b, b + len - 1)? "Yes": "No");
    }
    return 0;
}