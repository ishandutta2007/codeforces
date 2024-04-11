#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

const int N =  55;
int n, m;
char a[N], b[N];
bool work() {
	read(n); read(m);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	while (n && m && a[n] == b[m]) n--, m--;
	if (m == 0) return true;
	if (m == 1) {
		while (n) if (a[n] == b[m]) break; else n--;
		return n > 0;
	}
	return false;
}
int main() {
	int T;
	read(T);
	while (T--) puts(work() ? "YES" :"NO");


}