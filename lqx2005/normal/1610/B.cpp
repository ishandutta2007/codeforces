#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define node pair<ll, int>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e5 + 10, P1 = 1e9 + 7, P2 = 1e9 + 9;
int n, a[N], b[N];

int check(int x) {
    int tot = 0;
    for(int i = 1; i <= n; i++) if(a[i] != x) b[++tot] = a[i];
    for(int i = 1; i <= tot; i++) if(b[i] != b[tot + 1 - i]) return 0;
    return 1;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int pos = -1;
    for(int i = 1; i <= n; i++) {
        if(a[i] != a[n + 1 - i]) {
            pos = i;
            break;
        }
    }
    if(pos == -1) {
        cout << "YES" << endl;
        return;
    }
    if(check(a[pos]) || check(a[n + 1 - pos])) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;
}

int main() {
    int t;
    for(cin >> t; t--; solve());
    return 0;
}