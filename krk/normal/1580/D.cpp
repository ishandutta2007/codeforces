#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 4004;
const ll Inf = 1000000000000000000ll;

int n, m;
ll a[Maxn];
vector <int> seq;
int L[Maxn], R[Maxn];
int sz[Maxn];
ll res[Maxn][Maxn];

void Solve(int v)
{
    if (v == 0) return;
    fill(res[v], res[v] + Maxn, -Inf);
    Solve(L[v]);
    Solve(R[v]);
    sz[v] = sz[L[v]] + sz[R[v]] + 1;
    for (int i = 0; i <= sz[L[v]]; i++)
        for (int j = 0; j <= sz[R[v]]; j++) {
            // don't take
            res[v][i + j] = max(res[v][i + j], res[L[v]][i] + res[R[v]][j] - 2ll * ll(i) * j * a[v]);
            // take
            res[v][i + j + 1] = max(res[v][i + j + 1], res[L[v]][i] + res[R[v]][j] + ll(m - 1) * a[v] - 2ll * (ll(i) * j + i + j) * a[v]);
        }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        while (seq.size() >= 2 && a[seq[int(seq.size()) - 2]] > a[i]) {
            int B = seq.back(); seq.pop_back();
            int A = seq.back();
            R[A] = B;
        }
        if (!seq.empty() && a[seq.back()] > a[i]) {
            int B = seq.back(); seq.pop_back();
            L[i] = B;
        }
        seq.push_back(i);
    }
    while (seq.size() >= 2) {
        int B = seq.back(); seq.pop_back();
        int A = seq.back();
        R[A] = B;
    }
    int root = seq[0];
    Solve(root);
    cout << res[root][m] << endl;
    return 0;
}