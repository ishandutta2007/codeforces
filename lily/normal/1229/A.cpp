#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 7777

int n;
LL a[N]; int b[N];
vector <LL> ok;
map <LL, int> G;

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		G[a[i]]++;
	}
	
	LL ans = 0;
	for (int i = 1; i <= n; i++) read(b[i]);
	
	for (int i = 1; i <= n; i++) if (G[a[i]] > 1) ok.push_back(a[i]), ans += b[i], a[i] = -1;
	
	for (int i = 1; i <= n; i++) if (a[i] != -1) {
		for (auto &v : ok) if ((a[i] & v) == a[i]) {
			a[i] = -1;
			ans += b[i];
			break;
		}
	}
	cout << ans << endl;
}