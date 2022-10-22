#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
using namespace std;
int n, k;
int a[55];
void rmain() {
    cin >> n >> k;
    int o = 0;
    FOR(i, 1, n) cin >> a[i], o |= a[i];
    if(o) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main() {
    int T;
    for(cin >> T; T--; ) rmain();
}