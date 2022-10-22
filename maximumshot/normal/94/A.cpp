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

    map<string, int> m;

    for (int i = 0; i < 10; i++) {
        string t;
        cin >> t;
        m[t] = i;
    }

    for (int i = 0; i < (int) s.size(); i += 10) {
        string tt = s.substr(i, 10);
        cout << m[tt];
    }

    cout << "\n";

    return 0;
}