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
		vector <int> a;
		for (int i = n ; i > 0; i -= 2) {
			if (i != 1) a.push_back({i - 1});
			a.push_back(i);
		}
		reverse(a.begin(), a.end());
		for (auto i : a) printf("%d ", i);
		printf("\n");
	}
}