#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000100;
const int MAXM = 255;

int n, m;
ll x[MAXN], y[MAXN];
int best[MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) cin >> x[i] >> y[i];
    for (int i=1; i<=n; i++) best[i] = 1;
    for (int i=0; i<m; i++)
        for (int j=i+1; j<m; j++)
            if (y[i] != y[j]) {
                ll a = y[i]*x[j]-x[i]*y[j], b = y[i]-y[j];
                if (a%b == 0) {
                    ll c = a/b;
                    if (c>0 && c<=n) {
                        int cur = 0;
                        for (int k=0; k<m; k++)
                            if (k == i || k == j || c*(y[i]-y[k]) == y[i]*x[k]-x[i]*y[k])
                                cur++;
                        best[c] = max(best[c], cur);
                    }
                }
            }

    ll ans = 0;
    for (int i=1; i<=n; i++) ans += best[i];
    cout << ans << '\n';
}