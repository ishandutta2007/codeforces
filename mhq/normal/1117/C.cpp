#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  y1 aabcbacba
const int maxN = 2 * (int)1e5 + 100;
string s;
int prefX[maxN], prefY[maxN];
ll x1, y1, x2, y2;
int n;
void upd(ll a, ll b, ll& c) {
    if (c < 0) return ;
    if (a <= 0) return ;
    if (b == 0) {
        c = -1;
        return ;
    }
    c = max(c, (a + b - 1) / b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    cin >> s;
    prefX[0] = prefY[0] = 0;
    for (int i = 0; i < s.size(); i++) {
        prefX[i + 1] = prefX[i];
        prefY[i + 1] = prefY[i];
        if (s[i] == 'U') prefY[i + 1]++;
        else if (s[i] == 'D') prefY[i + 1]--;
        else if (s[i] == 'L') prefX[i + 1]--;
        else prefX[i + 1]++;
    }
    ll shiftX = prefX[n];
    ll shiftY = prefY[n];
    ll best = (ll)1e18;
    for (int pos = 0; pos <= n; pos++) {
        ll nX = x2 - x1 - prefX[pos];
        ll nY = y2 - y1 - prefY[pos];
        ll limK = 0;
        for (int i = -1; i <= 1; i += 2) {
            for (int j = -1; j <= 1; j += 2) {
                upd(nX * i + nY * j - pos, n + shiftX * i + shiftY * j, limK);
            }
        }
        if (limK < 0) continue;
        best = min(best, limK * n + pos);
    }
    if (best < (ll)1e17) cout << best;
    else cout << -1;
}