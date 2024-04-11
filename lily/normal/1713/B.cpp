#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)



int main() {
	int T;
	read(T);
	while (T--) {
		int n;
		read(n);
		vector <int> a, b;
		for (int i = 1; i <= n; i++) {
			int x;
			read(x);
			a.push_back(x);
		}
		b = a;
		sort(a.begin(), a.end());
		int i = 0, j = n - 1;
		for (auto k : a) {
			if (k == b[i]) i++;
			else if (k == b[j]) j--;
			else {
				i = -1;
				break;
			}
		}
		puts (i == -1 ? "NO" : "YES");
	}
}