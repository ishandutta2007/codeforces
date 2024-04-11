#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int ok = 1;
        for (int i = 0; i < n; i++) ok &= (a[i] == '0') || (b[i] == '0');
        cout << (ok ? "YES" : "NO") << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}