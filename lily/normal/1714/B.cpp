#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

const int N = 2e5 + 5;
int n;
int a[N];
void work() {
	read(n);
	for (int i = 1; i<= n; i++) read(a[i]);
	set <int> vis;
	int ans = 0;
	for (int i = n; i; i--) {
		if (vis.count(a[i])) {ans = i; break;}
		vis.insert(a[i]);
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	read(T);
	while (T--) work();

}