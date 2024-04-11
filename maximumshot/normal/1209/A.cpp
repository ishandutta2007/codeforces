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

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < n; i++) {
        int ok = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] % a[j] == 0) {
                ok = 0;
                break;
            }
        }
        res += ok;
    }

    cout << res << "\n";

    return 0;
}