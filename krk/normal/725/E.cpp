#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Inf = 1000000000;

int c, n;
int a[Maxn];
ll sum[Maxn];
int BIT[Maxn];
vector <ii> my[Maxn];
int res = Inf;

ll getSum(int a, int b)
{
    ll res = sum[b];
    if (a) res -= sum[a - 1];
    return res;
}

void addBIT(int ind, int val)
{
    for (int i = ind + 1; i > 0; i -= i & -i)
        BIT[i] = min(BIT[i], val);
}

int getBIT(int ind)
{
    int res = Inf;
    for (int i = ind + 1; i < Maxn; i += i & -i)
        res = min(res, BIT[i]);
    return res;
}

void Insert(const ii &p, int n)
{
    if (p.first == 0) return;
    int ind = upper_bound(a, a + n, p.first) - a - 1;
    if (ind < 0) res = min(res, p.second);
    else my[ind].push_back(p);
}

int main()
{
    scanf("%d %d", &c, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        sum[i] = a[i];
        if (i) sum[i] += sum[i - 1];
    }
    fill(BIT, BIT + Maxn, Inf);
    for (int i = n - 1; i >= 0; i--) {
        if (c >= a[i]) {
            Insert(ii(c - a[i], a[i]), i + 1);
            c -= a[i];
        }
        for (int j = 0; j < my[i].size(); j++) {
            ii p = my[i][j];
            addBIT(i, p.first + p.second);
            int l = 0, r = i;
            while (l <= r) {
                int m = l + r >> 1;
                if (getSum(m, i) <= p.first) r = m - 1;
                else l = m + 1;
            }
            p.first -= getSum(l, i);
            Insert(p, l);
        }
        int got = getBIT(i);
        if (got < Inf)
            Insert(ii(a[i] - 1, got - (a[i] - 1)), i);
    }
    assert(c == 0);
    if (res >= Inf) printf("Greed is good\n");
    else printf("%d\n", res);
    return 0;
}