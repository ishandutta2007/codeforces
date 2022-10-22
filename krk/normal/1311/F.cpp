#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ll> ill;

const int Maxn = 200005;

int n;
ii xv[Maxn];
vector <int> un;
ill BIT[Maxn];
ll res;

ill Get(int x)
{
    ill res = ill(0, 0ll);
    x++;
    for (int i = x; i > 0; i -= i & -i) {
        res.first += BIT[i].first;
        res.second += BIT[i].second;
    }
    return res;
}

void Add(int x, ill p)
{
    x++;
    for (int i = x; i < Maxn; i += i & -i) {
        BIT[i].first += p.first;
        BIT[i].second += p.second;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &xv[i].first);
    for (int i = 0; i < n; i++) {
        scanf("%d", &xv[i].second);
        un.push_back(xv[i].second);
    }
    sort(xv, xv + n);
    sort(un.begin(), un.end());
    un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(un.begin(), un.end(), xv[i].second) - un.begin();
        ill got = Get(ind);
        res += ll(got.first) * xv[i].first - got.second;
        Add(ind, ill(1, xv[i].first));
    }
    cout << res << endl;
    return 0;
}