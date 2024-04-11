#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a);

int n, K;
void work () {
	read(n);
	vector <int> a(n + 1);
	vector <int> zero(n + 1), one(n + 1);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		zero[i] = zero[i - 1];
		one[i] = one[i - 1];
		if (a[i] == 1) one[i] ++;
		else zero[i] ++;
	}
	int ans = n;
	if (one[n] == n || zero[n] == n) ans = 0;
	for (int i = 1; i < n; i++) {
		int le = one[i];
		int ri = zero[n] - zero[i]; 
		ans = min(ans, le + ri - min(le, ri));
	}
	printf("%d\n", ans);


}

int main() {
	int T;
	read(T);
	while (T--) work();
}