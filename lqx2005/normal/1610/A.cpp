#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<ll, int>
using namespace std;
typedef long long ll;
typedef double db;
void solve() {
    int n, m;
    cin >> n >> m;
    if(n == 1 && m == 1) cout << 0 << endl;
    else if(n == 1 || m == 1) cout << 1 << endl;
    else cout << 2 << endl;
    return;
}

int main() {
    int t;
    for(cin >> t; t--; solve());
    return 0;
}