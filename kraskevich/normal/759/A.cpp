#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 200 * 1000 + 10;

int p[N];
bool was[N];

void dfs(int v) {
    was[v] = true;
    if (!was[p[v]])
        dfs(p[v]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;    
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tot += x;
    }
    int ans = (tot + 1) % 2;
    int cyc = 0;
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            cyc++;
            dfs(i);
        }
    if (cyc > 1)
        ans += cyc;
    cout << ans << endl;
}