#include <bits/stdc++.h>

using namespace std;
const int maxN = (int)1e5 + 10;
const int INF  = (int)1e9;
int n;
int a[maxN];
int d[maxN];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = INF;
    }
    for (int i = 1; i <= n; i++) {
        int ind = upper_bound(d, d + n + 1, a[i]) - d;
        d[ind] = a[i];
    }
    for (int i = n; i >= 1; i--) {
        if (d[i] <= n) {
            cout << i;
            break;
        }
    }
	return 0;
}