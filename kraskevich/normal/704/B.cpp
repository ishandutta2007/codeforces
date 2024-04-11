#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5005;
const ll INF = (ll) 1e18;

ll f[N][5];
ll new_f[N][5];
ll x[N];
ll a[N];
ll b[N];
ll c[N];
ll d[N];

int main() {
    ios_base::sync_with_stdio(0);
    int n, s, e;
    cin >> n >> s >> e;
    s--;
    e--;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 5; j++)
            f[i][j] = INF;
    f[0][2] = 0;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++)
            for (int k = 0; k < 5; k++)
                new_f[j][k] = INF;
        for (int L = 0; L <= n; L++) {
            for (int delta = 0; delta < 5; delta++) {
                    if (f[L][delta] == INF)
                        continue;
                    int R = L + delta - 2;
                    if (R > n || R < 0)
                        continue;
                    for (int d1 = 0; d1 < 2; d1++) {
                        for (int d2 = 0; d2 < 2; d2++) {
                            ll add = 0;
                            int newL = L, newR = R, newDelta = delta;
                            if (i != s) {
                                if (d1 == 0) {
                                    if (R == 0)
                                        continue;
                                    add += x[i] + a[i];
                                    newR--;
                                } else {
                                    add += -x[i] + b[i];
                                    newL++;
                                }
                            }
                            if (i != e) {    
                                if (d2 == 0) {
                                    if (L == 0)
                                        continue;
                                     add += x[i] + c[i];
                                     newL--;
                                 } else {
                                    add += -x[i] + d[i];
                                    newR++;                                
                                 }
                            }
                            if (i != n - 1 && newL == 0 && newR == 0)
                                continue;
                            assert (newL >= 0 && newR >= 0);
                            if (newL > n || newR > n)
                                continue;
                            newDelta = newR - newL + 2;
                            if (newDelta < 0 || newDelta >= 5)
                                continue;                         
                            new_f[newL][newDelta] = min(new_f[newL][newDelta], f[L][delta] + add);
                        }
                    }
                }
                 
        } 
        for (int j = 0; j <= n; j++)
            for (int k = 0; k < 5; k++)
                    f[j][k] = new_f[j][k];                       
    }
    cout << f[0][2] << endl;
    return 0;
}