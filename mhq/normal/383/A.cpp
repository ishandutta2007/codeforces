#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 10;
int n;
int a[maxN];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) cnt++;
        else ans += cnt;
    }
    cout << ans;
	return 0;
}