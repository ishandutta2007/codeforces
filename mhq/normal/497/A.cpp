#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m;
const int maxN = 105;
char s[maxN][maxN];
bool bad[maxN];
bool already[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i + 1 <= n; i++) {
            if (already[i]) continue;
            if (s[i][j] > s[i + 1][j]) {
                bad[j] = true;
            }
        }
        if (!bad[j]) {
            for (int i = 1; i + 1 <= n; i++) {
                if (already[i]) continue;
                if (s[i][j] < s[i + 1][j]) {
                    already[i] = true;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (bad[i]) cnt++;
    }
    cout << cnt;
    return 0;
}