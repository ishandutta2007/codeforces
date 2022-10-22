#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
const int N = 50 + 10;
int n, a[N];
void solve() {
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i] - 1;
    if(sum & 1) cout << "errorgorn\n";
    else cout << "maomao90\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}