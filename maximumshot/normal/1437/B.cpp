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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c0 = 0, c1 = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                if (s[i] == '1')
                    c1++;
                else
                    c0++;
            }
        }
        cout << max(c0, c1) << "\n";
    }

    return 0;
}