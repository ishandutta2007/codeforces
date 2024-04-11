#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a);

int n, K;
void work () {
	read(n); read(K);
	vector <int> a;
	bool hasone = false;
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		a.push_back(x);
		if (x) hasone = true; 
	}
	puts (hasone ? "YES" : "NO");
}

int main() {
	int T;
	read(T);
	while (T--) work();
}