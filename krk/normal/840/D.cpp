#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, q;
int a[Maxn];
vector <int> ind[Maxn];
bool tested[Maxn];
int seq[Maxn], slen;

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ind[a[i]].push_back(i);
    }
    for (int i = 0; i < q; i++) {
        int l, r, k; scanf("%d %d %d", &l, &r, &k);
        int nd = (r - l + 1) / k;
        nd++;
        for (int i = 0; i < slen; i++)
            tested[seq[i]] = false;
        slen = 0;
        int res = -1;
        for (int j = 0; j < 110; j++) {
            int in = uniform_int_distribution<int>(l, r)(rng);
            int x = a[in];
            if (res != -1 && x >= res || ind[x].size() < nd) continue;
            if (tested[x]) continue;
            tested[x] = true; seq[slen++] = x;
            int has = upper_bound(ind[x].begin(), ind[x].end(), r) -
                      lower_bound(ind[x].begin(), ind[x].end(), l);
            if (has >= nd) res = x;
        }
        printf("%d\n", res);
    }
    return 0;
}