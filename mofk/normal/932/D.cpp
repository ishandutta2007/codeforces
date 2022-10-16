#include <bits/stdc++.h>

using namespace std;

int q;
int n = 1;
int dad[500005];
long long wei[500005];
int nxt[500005][20];
long long f[500005][20];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> q;
    long long last = 0;
    wei[0] = 1e16 + 7;
    for (int i = 1; i < 20; ++i) f[1][i] = 1e16 + 7;
    while (q--) {
        int type;
        long long u, w;
        cin >> type >> u >> w;
        u ^= last; w ^= last;
        //cout << (type == 1 ? "add " : "get ") << u << ' ' << w << endl;
        if (type == 1) {
            ++n;
            dad[n] = u;
            wei[n] = w;
            nxt[n][0] = dad[n];
            while (wei[nxt[n][0]] < wei[n]) nxt[n][0] = nxt[nxt[n][0]][0];
            f[n][0] = wei[n];
            for (int i = 1; i < 20; ++i) {
                nxt[n][i] = nxt[nxt[n][i-1]][i-1];
                if (nxt[n][i-1] == 0) f[n][i] = 1e16 + 7;
                else f[n][i] = f[n][i-1] + f[nxt[n][i-1]][i-1];
            }
            //cout << nxt[n][0] << endl;
        }
        else {
            int ans = 0;
            long long curw = 0;
            for (int i = 19; i >= 0; --i) {
                if (u && curw + f[u][i] <= w) {
                    curw += f[u][i];
                    ans += 1 << i;
                    u = nxt[u][i];
                    //cout << ans << ' ' << u << ' ' << curw << endl;
                }
            }
            cout << ans << '\n';
            last = ans;
        }
    }
    return 0;
}