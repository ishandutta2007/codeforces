#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    if (r == 1 && c == 1) {
        cout << "0\n";
        return 0;
    }

    if (r == 1) {
        for (int i = 2; i <= c + 1; i++)
            cout << i << " ";
        cout << "\n";
        return 0;
    }

    if (c == 1) {
        for (int i = 2; i <= r + 1; i++) {
            cout << i << "\n";
        }
        return 0;
    }

    for (int i = 2; i <= c + 1; i++)
        cout << i << " ";
    cout << "\n";

    for (int i = 1; i < r; i++) {
        for (int j = 2; j <= c + 1; j++) {
            cout << j * (c + 1 + i) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    return 0;
}