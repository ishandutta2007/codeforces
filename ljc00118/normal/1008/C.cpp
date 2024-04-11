#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

int a[N], b[N];
int x = 1, y = 1, ans = 0;

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) b[i] = a[i];
	while(x <= n && y <= n) {
		if(a[x] < b[y]) ans++, x++, y++;
		else y++;
	}
	cout << ans << endl;
	return 0;
}