#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)
const int N = 2e5 + 5;
int n;
char s[N], a[N], b[N];
void work() {
	read(n);
	scanf("%s", s + 1);
	a[n + 1] = b[n + 1] = 0;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') a[i] = b[i] = '(';
		else {
			if (cur) b[i] = ')', a[i] = '(';
			else a[i] = ')', b[i] = '(';
			cur ^= 1;
		}
	}
	if (cur != 0) {
		puts("NO");
		return;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0) {
			puts("NO");
			return;
		}
	}
	if (cnt % 2) {
		puts("NO");
		return;
	}
	for (int i = n; i; i--) if (cnt > 0 && s[i] == '1') {
		cnt -= 2;
		a[i] = b[i] = ')';
	}
	
	if (cnt) {
		puts("NO");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0) {
			puts("NO");
			return;
		}
	}
	if (cnt) {
		puts("NO");
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (b[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0) {
			puts("NO");
			return;
		}
	}
	if (cnt) {
		puts("NO");
		return;
	}
	puts("YES");
	puts(a + 1);
	puts(b + 1);


}
int main() {
	int T;
	read(T);
	while (T--) work();
}