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
		for (int i = 0; i < n; i++) {
			int x;
			read(x);
			a.push_back(x);
		}
		set <int> zero, cur;
		for (int i = 0; i < n; i++) {
			int x = a[i];
			if (zero.count(x)) x = 0;
			if (cur.size() && *cur.rbegin() > x) {
				for (auto j : cur) zero.insert (j);
				cur.clear();
			}
			cur.insert(x);
		}
		printf("%d\n", (int)zero.size() - zero.count(0));
	}
}