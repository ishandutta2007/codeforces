#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        for (int it = 0; it < m; it++) {
            vector<int> upd;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1')
                    continue;
                int cnt = 0;
                if (i > 0 && s[i - 1] == '1') cnt++;
                if (i + 1 < n && s[i + 1] == '1') cnt++;
                if (cnt == 1)
                    upd.push_back(i);
            }
            if (upd.empty()) break;
            for (int i : upd)
                s[i] = '1';
        }
        cout << s << "\n";
    }

    return 0;
}