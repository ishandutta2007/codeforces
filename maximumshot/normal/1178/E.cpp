#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = (int) s.size();

    string t;

    for (int l = 0, r = n - 1; l + 1 < r - 1; l += 2, r -= 2) {
        if (s[l] == s[r] || s[l] == s[r - 1]) {
            t.push_back(s[l]);
        } else {
            t.push_back(s[l + 1]);
        }
    }

    cout << t;

    if (n % 2 == 1 || n % 4 != 0) {
        cout << s[n / 2];
    }

    reverse(t.begin(), t.end());

    cout << t << "\n";

    return 0;
}