#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, ll> iill;

const int Maxn = 100005;

int n, m;
ll st[Maxn];
vector <int> pos, neg;
vector <iill> res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        st[a] += c; st[b] -= c;
    }
    for (int i = 1; i <= n; i++)
        if (st[i] > 0) pos.push_back(i);
        else if (st[i] < 0) neg.push_back(i);
    while (!pos.empty()) {
        int a = pos.back(), b = neg.back();
        ll tk = min(st[a], -st[b]);
        st[a] -= tk; st[b] += tk;
        res.push_back(iill(ii(a, b), tk));
        if (st[a] == 0) pos.pop_back();
        if (st[b] == 0) neg.pop_back();
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d %I64d\n", res[i].first.first, res[i].first.second, res[i].second);
    return 0;
}