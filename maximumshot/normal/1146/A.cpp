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

    string s;

    cin >> s;

    int cnt = 0;

    for (char c : s) {
        cnt += c == 'a';
    }

    cout << min((int)s.size(), 2 * cnt - 1) << "\n";

    return 0;
}