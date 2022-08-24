#include <bits/stdc++.h>
using namespace std;
int n;
map < int, int > a;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
        mx = max(mx, a[x]);
    }
    cout << mx;
	return 0;
}