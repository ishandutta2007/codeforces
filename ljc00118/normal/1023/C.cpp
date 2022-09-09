#include<bits/stdc++.h>
using namespace std;

char a[200005], ans[200005];
int n, m, k;

int main() {
	cin >> n >> m;
	scanf("%s", a + 1);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == '(') ans[++tot] = '(';
		else {
			if (m < n) {
				m += 2;
				tot--;
			}
			else ans[++tot] = ')';
		}
	}
	for (int i = 1; i <= tot; i++) printf("%c", ans[i]);
	return 0; 
}