#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int q;
vector <ii> quer[Maxn];
ll qres[Maxn];
vector <int> one[Maxn], two[Maxn];
ll BIT[Maxn];
int l, r;

void Add(int x, ll val)
{
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i] += val;
}

ll Get(int x)
{
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r; scanf("%d %d", &l, &r);
        quer[l].push_back(ii(r, i));
    }
    for (int i = Maxn - 1; i > 0; i--) {
        for (int j = i + i; j < Maxn; j += i) {
            ll got = one[j].size();
            got += two[j].end() - upper_bound(two[j].begin(), two[j].end(), j - i);
            one[j].push_back(i);
            if (got) Add(j, got);
        }
        if (i % 2 == 0)
            for (int j = i + i / 2; j < Maxn; j += i) {
                ll got = one[j].end() - upper_bound(one[j].begin(), one[j].end(), j - i);
                got += two[j].end() - upper_bound(two[j].begin(), two[j].end(), j - i);
                two[j].push_back(i);
                if (got) Add(j, got);
            }
        for (int j = 0; j < quer[i].size(); j++) {
            int l = i, r = quer[i][j].first, ind = quer[i][j].second;
            ll sz = r - l + 1;
            qres[ind] = sz * (sz - 1) * (sz - 2) / 6 - Get(r);
        }
    }
    for (int i = 0; i < q; i++)
        printf("%I64d\n", qres[i]);
    return 0;
}