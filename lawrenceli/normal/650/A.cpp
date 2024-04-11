#include <bits/stdc++.h>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;

map<int, int> mx, my;
map<pii, int> mxy;

int n;
ll ans;

ll C2(int n) { return ll(n) * (n - 1) / 2; }

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mx[x]++;
        my[y]++;
        mxy[pii(x, y)]++;
    }

    for (auto i : mx)
        ans += C2(i.B);

    for (auto i : my)
        ans += C2(i.B);

    for (auto i : mxy)
        ans -= C2(i.B);

    cout << ans << '\n';
}