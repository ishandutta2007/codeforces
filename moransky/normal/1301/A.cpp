#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 105;
char a[N], b[N], c[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s%s%s", a, b, c);
		int n = strlen(a);
		bool ok = true;
		for (int i = 0; i < n; i++){
			if (c[i] != a[i] && c[i] != b[i]) { ok = false; break; }
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}