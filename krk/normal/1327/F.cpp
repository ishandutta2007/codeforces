#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 500005;
const int Maxb = 30;
const int mod = 998244353;

int n, k, m;
vector <ii> my[Maxn];
ii seq[Maxb][Maxn];
int st[Maxb], en[Maxb], tot[Maxb];

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 0; i < m; i++) {
        int l, r, x; scanf("%d %d %d", &l, &r, &x);
        my[r].push_back(ii(l, x));
    }
    for (int b = 0; b < k; b++) {
        seq[b][en[b]++] = ii(0, 1);
        tot[b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int b = 0; b < k; b++) {
            seq[b][en[b]++] = ii(i, tot[b]);
            tot[b] = (tot[b] + tot[b]) % mod;
        }
        for (int j = 0; j < my[i].size(); j++) {
            int lef = my[i][j].first, nd = my[i][j].second;
            for (int b = 0; b < k; b++)
                if (nd & 1 << b)
                    while (st[b] < en[b] && seq[b][en[b] - 1].first >= lef) {
                        tot[b] = (tot[b] - seq[b][en[b] - 1].second + mod) % mod;
                        en[b]--;
                    }
                else while (st[b] < en[b] && seq[b][st[b]].first < lef) {
                    tot[b] = (tot[b] - seq[b][st[b]].second + mod) % mod;
                    st[b]++;
                }
        }
    }
    int res = 1;
    for (int b = 0; b < k; b++)
        res = ll(res) * tot[b] % mod;
    cout << res << endl;
    return 0;
}