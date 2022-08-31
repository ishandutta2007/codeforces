#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
const int maxN = 105;
bool ok[maxN][maxN];
int main() {
   // freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int r;
        cin >> r;
        for (int j = 1; j <= r; j++) {
            int x;
            cin >> x;
            ok[i][x] = true;
        }
    }
    for (int i = 1; i <= 100; i++) {
        bool can = true;
        for (int j = 1; j <= n; j++) {
            can &= ok[j][i];
        }
        if (can) cout << i << " ";
    }
    return 0;
}