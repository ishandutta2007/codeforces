#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, ll> ill;

const int Maxn = 300005;

struct BIT {
    vector <ll> a;
    int n;
    BIT(int g = 0) {
        n = g + 1;
        a.resize(n);
    }
    void Add(int x, ll val) {
        for (int i = x + 1; i < a.size(); i += i & -i)
            a[i] += val;
    }
    ll Get(int x) {
        ll res = 0;
        for (int i = x + 1; i > 0; i -= i & -i)
            res += a[i];
        return res;
    }
};

int n, q;
char str[Maxn];
int a[Maxn];
int head[Maxn], id[Maxn];
vector <int> S;
BIT bit[Maxn];
int C[Maxn];
BIT all;
int qt[Maxn], ql[Maxn], qr[Maxn];
vector <int> quer[Maxn];
ll res[Maxn];

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + (str[i] == '('? 1: -1);
    S.push_back(0);
    head[0] = 0; id[0] = 0;
    all = BIT(n + 1);
    for (int i = 1; i <= n; i++) {
        while (!S.empty() && a[S.back()] > a[i]) {
            int h = head[S.back()];
            C[h] = id[S.back()] + 1;
            bit[h] = BIT(C[h]);
            for (int i = 0; i < C[h]; i++)
                bit[h].Add(i, 1);
            all.Add(h, ll(C[h]) * (C[h] - 1) / 2ll);
            S.pop_back();
        }
        if (S.empty() || a[S.back()] != a[i]) {
            head[i] = i; id[i] = 0;
            S.push_back(i);
        } else {
            head[i] = head[S.back()]; id[i] = id[S.back()] + 1;
            S.back() = i;
        }
    }
    while (!S.empty()) {
            int h = head[S.back()];
            C[h] = id[S.back()] + 1;
            bit[h] = BIT(C[h]);
            for (int i = 0; i < C[h]; i++)
                bit[h].Add(i, 1);
            all.Add(h, ll(C[h]) * (C[h] - 1) / 2ll);
            S.pop_back();
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &qt[i], &ql[i], &qr[i]);
        if (qt[i] == 1) {
            int h = head[ql[i]];
            all.Add(h, -ll(C[h]) * (C[h] - 1) / 2ll);
            C[h]--;
            all.Add(h, ll(C[h]) * (C[h] - 1) / 2ll);
            bit[h].Add(id[ql[i]], -1);
            h = head[qr[i]];
            all.Add(h, -ll(C[h]) * (C[h] - 1) / 2ll);
            C[h]--;
            all.Add(h, ll(C[h]) * (C[h] - 1) / 2ll);
            bit[h].Add(id[qr[i]], -1);
        } else {
            ql[i]--;
            ll res = all.Get(qr[i]) - all.Get(ql[i]);
            int h = head[ql[i]];
            int cnt = bit[h].Get(id[qr[i]]) - bit[h].Get(id[ql[i]]);
            res += ll(cnt) * (cnt + 1) / 2ll;
            printf("%I64d\n", res);
        }
    }
    return 0;
}