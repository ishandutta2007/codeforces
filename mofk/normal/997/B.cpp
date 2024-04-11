#include <bits/stdc++.h>

using namespace std;
typedef vector <vector <int> > mt;

const int coin[] = {4, 9};
int n;
int d[50];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < 50; ++i) d[i] = -1;
    queue <int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < 2; ++i) {
            int v = (u + coin[i]) % 49;
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 49; ++i) if (d[i] <= n) ans += n - d[i] + 1;
    cout << ans << endl;
    return 0;
}