#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;

int n, m, q;
int a[Maxn];
vector <int> seq;
ll sum[Maxn];
int par[Maxn];
int siz[Maxn];
int R[Maxn];
ll tot;
ii quer[Maxn];
ll qres[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

ll Get(int en, int hm) { return sum[en] - (hm <= en? sum[en - hm]: 0ll); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    tot -= (Get(R[a], siz[a]) + Get(R[b], siz[b]));
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    R[a] = max(R[a], R[b]);
    tot += Get(R[a], siz[a]);
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        seq.push_back(a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < m; i++) {
        int b; scanf("%d", &b);
        seq.push_back(b);
    }
    sort(seq.begin(), seq.end());
    for (int i = 0; i < seq.size(); i++) {
        sum[i] = seq[i];
        if (i) sum[i] += sum[i - 1];
    }
    vector <ii> difs;
    for (int i = 0; i + 1 < seq.size(); i++)
        difs.push_back(ii(seq[i + 1] - seq[i], i));
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
        siz[ind]++;
    }
    for (int i = 0; i < seq.size(); i++) {
        par[i] = i;
        R[i] = i;
        tot += Get(R[i], siz[i]);
    }
    sort(difs.begin(), difs.end());
    int pnt = 0;
    while (pnt < difs.size() && difs[pnt].first == 0) {
        unionSet(difs[pnt].second, difs[pnt].second + 1);
        pnt++;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &quer[i].first);
        quer[i].second = i;
    }
    sort(quer, quer + q);
    for (int i = 0; i < q; i++) {
        ll add = quer[i].first;
        int ind = quer[i].second;
        while (pnt < difs.size() && difs[pnt].first <= add) {
            unionSet(difs[pnt].second, difs[pnt].second + 1);
            pnt++;
        }
        qres[ind] = tot;
    }
    for (int i = 0; i < q; i++)
        printf("%I64d\n", qres[i]);
    return 0;
}