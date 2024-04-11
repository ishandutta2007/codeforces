#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int N = (int)1e6 + 10;

const ll MOD = 1000 * 1000 * 1000 + 7;

vector<int> ds[N];
int min_p[N];
int ans[N][22];

void init() {
    for (int i = 0; i < N; i++)
        min_p[i] = i;
    for (int i = 2; i < N; i++)
        if (min_p[i] == i) {
            ds[i].push_back(1);
            for (int j = 2 * i; j < N; j += i) {
                int c = j;
                ds[j].push_back(0);
                while (c % i == 0) {
                    ds[j].back()++;
                    c /= i;
                }
                min_p[j] = min(min_p[j], i); 
            }
        }
    for (int d = 0; d < 22; d++)
        ans[0][d] = (d == 0 ? 1 : 2);
    for (int i = 1; i < N; i++)
        for (int d = 0; d < 22; d++) {
            ans[i][d] = ans[i - 1][d];
            if (d)
                ans[i][d] = (ans[i][d - 1] + ans[i][d]) % MOD;
        }
}

int solve(int n, int r) {
    int res = 1;
    for (int d : ds[n])
        res = res * 1ll * ans[r][d] % MOD;
    return res;
}

int main() {
    init();
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int r, n;
        scanf("%d%d", &r, &n);
        printf("%d\n", solve(n, r));
    }
}