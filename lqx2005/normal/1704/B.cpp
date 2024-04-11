#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define db double
#define x first
#define y second
#define vi vector<int>
using namespace std;
int n, x;
void solve() {
    cin >> n >> x;
    int l = -2e9 - 1, r = -l;
    int cnt = 0;
    FOR(i, 1, n) {
        int a;
        cin >> a;
        l = max(l, a - x), r = min(r, a + x);
        if(l > r) {
            cnt++;
            l = a - x, r = a + x;
        }
    }
    cout << cnt << "\n";
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}