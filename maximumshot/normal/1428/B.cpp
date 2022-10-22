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

        int le = 0, ri = 0;
        for (char c : s) {
            if (c == '>')
                ri = 1;
            if (c == '<')
                le = 1;
        }

        if (!le || !ri) {
            cout << n << "\n";
            continue;
        }

        vector<int> used(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            queue<int> q;
            q.push(i);
            used[i] = 1;
            int cnt = 1;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                if (s[v] == '-') {
                    int to = (v + 1) % n;
                    if (!used[to]) {
                        used[to] = 1;
                        q.push(to);
                        cnt++;
                    }
                }
                if (s[(v + n - 1) % n] == '-') {
                    int to = (v + n - 1) % n;
                    if (!used[to]) {
                        used[to] = 1;
                        q.push(to);
                        cnt++;
                    }
                }
            }
            if (cnt > 1)
                res += cnt;
        }

        cout << res << "\n";
    }

    return 0;
}