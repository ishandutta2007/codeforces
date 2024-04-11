#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 500005;
const int Maxm = 4194304;

int n, m, q;
int freq[Maxn];
vector <int> tims[Maxn];
vector <lli> quer;
int res[Maxn];
int st[Maxm];

void Insert(int v, int l, int r, int x)
{
    st[v]++;
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) Insert(2 * v, l, m, x);
        else Insert(2 * v + 1, m + 1, r, x);
    }
}

int Get(int v, int l, int r, int ind)
{
    if (l == r) return l;
    else {
        int m = l + r >> 1;
        if (ind < st[2 * v]) return Get(2 * v, l, m, ind);
        else return Get(2 * v + 1, m + 1, r, ind - st[2 * v]);
    }
}

void insertAll(int pnt)
{
    for (int j = 0; j < tims[pnt].size(); j++) {
        int ind2 = tims[pnt][j];
        Insert(1, 1, m, ind2);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        int v; scanf("%d", &v);
        freq[v]++;
    }
    for (int i = 1; i <= m; i++)
        tims[freq[i]].push_back(i);
    for (int i = 0; i < q; i++) {
        ll x; scanf("%I64d", &x);
        x -= (n + 1);
        quer.push_back(lli(x, i));
    }
    sort(quer.begin(), quer.end());
    ll cur = 0, wascur = 0;
    int pnt = 0;
    insertAll(0);
    for (int i = 0; i < quer.size(); i++) {
        ll x = quer[i].first;
        int ind = quer[i].second;
        x -= wascur;
        while (pnt < Maxn && cur + int(tims[pnt].size()) <= x) {
            cur += int(tims[pnt].size());
            wascur += cur;
            x -= cur;
            pnt++;
            if (pnt < Maxn) insertAll(pnt);
        }
        int ind2 = x % st[1];
        res[ind] = Get(1, 1, m, ind2);
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", res[i]);
    return 0;
}