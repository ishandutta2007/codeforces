#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300005;
const int inf = 1e9;
const int num_trials = 100;

int n, q, a[maxn], l[maxn], r[maxn], k[maxn], need[maxn], ans[maxn];
int qb[maxn][num_trials], qv[maxn][num_trials];
vector<int> v[maxn];
vector<int> ql[maxn];
vector<int> qr[maxn];

int pre[maxn];

unsigned int hsh = 0;
unsigned int x = 0;

//ELF hash
void update_hash(int c) {
    hsh = (hsh << 4) + c;
    if ((x = hsh & 0xF0000000L) != 0) hsh ^= (x >> 24);
    hsh &= ~x;
}

int main() {
    scanf("%d %d", &n, &q);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[a[i]].push_back(i);
        update_hash(a[i]);
    }

    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &l[i], &r[i], &k[i]);
        l[i]--;
        update_hash(l[i]);
        update_hash(r[i]);
        update_hash(k[i]);
    }

    srand(hsh);

    for (int i = 0; i < q; i++) {
        int len = r[i] - l[i];
        need[i] = (r[i] - l[i]) / k[i];
        ql[l[i]].push_back(i);
        qr[r[i]].push_back(i);
        for (int j = 0; j < num_trials; j++) {
            qb[i][j] = a[(ll(rand()) * RAND_MAX + rand()) % len + l[i]];
        }
    }

    for (int i = 0; i < q; i++) ans[i] = inf;

    for (int p = 0; p <= n; p++) {
        for (int i : ql[p]) {
            for (int j = 0; j < num_trials; j++) {
                qv[i][j] = pre[qb[i][j]];
            }
        }

        for (int i : qr[p]) {
            for (int j = 0; j < num_trials; j++) {
                if (pre[qb[i][j]] - qv[i][j] > need[i])
                    ans[i] = min(ans[i], qb[i][j]);
            }
        }

        pre[a[p]]++;
    }

    for (int i = 0; i < q; i++)
        printf("%d\n", ans[i] == inf ? -1 : ans[i]);
}