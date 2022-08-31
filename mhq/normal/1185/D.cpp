#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2 * (int)1e5 + 100;
ll b[maxN];
bool goodP[maxN];
bool goodS[maxN];
map < ll, int > bck;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        bck[b[i]] = i;
    }
    sort(b + 1, b + n + 1);
    goodP[0] = true;
    for (int i = 1; i <= n; i++) {
        goodP[i] = goodP[i - 1];
        if (i >= 3 && (b[i] + b[i - 2] != 2 * b[i - 1])) {
            goodP[i] = false;
        }
    }
    goodS[n + 1] = true;
    for (int i = n; i >= 1; i--) {
        goodS[i] = goodS[i + 1];
        if (i + 2 <= n && (b[i + 2] + b[i] != 2 * b[i + 1])) {
            goodS[i] = false;
        }
    }
    for (int who = 1; who <= n; who++) {
        if (!goodP[who - 1] || !goodS[who + 1]) continue;
        if (who >= 3 && who + 1 <= n) {
            if ((b[who - 2] + b[who + 1]) != 2 * b[who - 1]) continue;
        }
        if (who >= 2 && who + 2 <= n) {
            if (b[who - 1] + b[who + 2] != 2 * b[who + 1]) continue;
        }
        cout << bck[b[who]];
        return 0;
    }
    cout << -1;
    return 0;
}