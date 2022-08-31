#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 2100, inf = 1000111222;

int n;
int m[max_n];
vector<int> ans;
void rev(int x) {
    reverse(m, m + x);
    ans.PB(x);
}

int find(int x) {
    for (int i = 0; i < n; ++i) {
        if (m[i] == x) {
            return i;
        }
    }
}

void solve() {
    for (int i = 0; i < n; ++i) {
        if (i % 2 == m[i] % 2) {
            return;
        }
    }
    int st = n;
    for (int cur = st; cur >= 3; cur -= 2) {
        int pc = find(cur);
        rev(pc + 1);
        int pp = find(cur - 1);
        rev(pp);
        rev(pp + 2);
        rev(3);
        rev(n);
        n -= 2;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        ans.clear();
        cin >> n;
        int st = n;
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
        }
        solve();
        if (ans.empty()) {
            puts("-1");
            continue;
        }
        cout << ans.size() << "\n";
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << "\n";
    }

    return 0;
}