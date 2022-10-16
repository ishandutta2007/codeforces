#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 1e6 + 5;

char s[N];

int n;

int main() {
	scanf("%d%s", &n, s + 1);
	int top = 0, last = 1, ans = 0;
	bool o = true;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') {
			++top;
		} else {
			if (top == 0) o = false;
			top--;
		}
		if (top == 0) {
			if (!o) ans += i - last + 1;
			last = i + 1, o = true;
		}
	}
	if (top) puts("-1");
	else printf("%d\n", ans);
	return 0;
}