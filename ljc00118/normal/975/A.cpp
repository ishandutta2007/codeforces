#include<bits/stdc++.h>
using namespace std;

string a[1000 + 10];
bool ok[200 + 10];
char c[1000 + 10];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		memset(ok, 0, sizeof(ok));
		string tmp = "";
		scanf("%s", c);
		int len = strlen(c);
		for(int j = 0; j < len; j++) ok[c[j]] = 1;
		int Len = -1;
		for(int j = 'a'; j <= 'z'; j++) {
			if(ok[j] == 1) tmp = tmp + (char)j;
		}
		a[i] = tmp;
	}
	sort(a + 1, a + n + 1);
	int ans = 1;
	for(int i = 1; i < n; i++) {
		if(a[i] != a[i + 1]) ans++;
	}
	printf("%d", ans);
	return 0;
}