#include<bits/stdc++.h>
using namespace std;

int a[1010], b[60];
bool ok[60];
int n, ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for(int i = n; i >= 1; i--) {
		if(a[b[i]] == 0) {
			a[b[i]] = 1;
			ans++;
		}
		else ok[i] = 1;
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) if(ok[i] == 0) printf("%d ", b[i]);
	return 0;
}