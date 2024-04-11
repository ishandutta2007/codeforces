#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x[4];

    for (int i = 0; i < 4; i++) {
        cin >> x[i];
    }

    sort(x, x + 4);

    for (int i = 0; i < 3; i++) {
        cout << x[3] - x[i] << " ";
    }

    cout << "\n";

    return 0;
}