#include<bits/stdc++.h>
using namespace std;

const int N = 3000 + 10;

int a[N], b[N];
int s[N];
int n, ans = 0x7fffffff;

int main() {
	memset(s, 0x3f, sizeof(s));
	cin >> n;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for(int i = 1; i < n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(a[j] > a[i]) s[i] = min(s[i], b[j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[j] > a[i]) {
				if(s[j] != 0x3f3f3f3f) ans = min(ans, b[i] + b[j] + s[j]);
			}
		}
	}
	if(ans == 0x7fffffff) ans = -1;
	cout << ans << endl;
	return 0;
}