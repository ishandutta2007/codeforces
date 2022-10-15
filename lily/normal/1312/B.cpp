#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second



int main() {

	int T;
	read(T);
	while (T--) {
		int n;read(n);
		vector <int> a;
		for (int i = 0 ;i < n; i++) {
			int x; read(x);
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		for (auto v : a) printf("%d ", v);
		puts("");
	}

}