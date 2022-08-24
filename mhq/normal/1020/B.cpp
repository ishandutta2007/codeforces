#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1005;
bool used[maxN];
bool incyc[maxN];
int p[maxN];
int to[maxN];
int n;
int dfs(int i) {
    if (to[i] > 0) return to[i];
    if (to[i] == 0) {
        to[i] = i;
        int x = p[i];
        while (x != i) {
            to[x] = x;
            x = p[x];
        }
        return to[i];
    }
    to[i] = 0;
    dfs(p[i]);
    if (to[i] == 0) {
        to[i] = to[p[i]];
        return to[i];
    }
    else return to[i];
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    memset(to, -1, sizeof to);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        if (to[i] == -1) dfs(i);
    }
    for (int i = 1; i <= n; i++) cout << to[i] << " ";
}