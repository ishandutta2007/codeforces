#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

const int N = 1000000 + 10;

int a[N], w[N];
int n;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		w[a[i]] = i;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] != i) {
			ans++;
			int tmp = a[i];
			swap(a[i], a[w[i]]);
			w[tmp] = w[a[i]];
		}
	}
	if(n % 2 == ans % 2) printf("Petr");
	else printf("Um_nik");
	return 0;
}