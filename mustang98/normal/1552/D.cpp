#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 11, inf = 1000111222;

int mm[max_n];
int m[max_n];
int n;
bool ok = false;

void rec(int pos, int val) {
    //cout << "$$ " << pos << ' ' << val << endl;
    if (pos == n - 1) {
        if (val == m[pos]) {
            ok = true;
        }
        return;
    }
    if (ok) {
        return;
    }
    rec(pos + 1, val);
    rec(pos + 1, val + m[pos]);
    rec(pos + 1, val - m[pos]);
}

bool solve() {
    if (n == 1) {
        if (m[0] == 0) {
            return true;
        }
        return false;
    }
    ok = false;
    for (int i = 0; i < n; ++i) {
        mm[i] = m[i];
    }
    for (int st = 0; st < n; ++st) {
        for (int i = 0; i < n; ++i) {
            m[i] = mm[i];
        }
        swap(m[st], m[n - 1]);
        rec(0, 0);
        if (ok) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
            m[i] = abs(m[i]);
        }
        sort(m, m + n);
        if (solve()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }


    return 0;
}