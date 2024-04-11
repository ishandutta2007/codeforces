#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

void work() {
	int n;
	read(n);
	vector <int> a; 
	for (int i = 1; i <= (1 << n); i++) a.push_back(i);
	while (a.size() > 1) {
		if (a.size() > 2) {
			vector <int> b;
			for (int i = 0; i < a.size(); i += 4) {
				printf("? %d %d\n", a[i], a[i + 2]);
				fflush(stdout);
				int res;
				scanf("%d", &res);
				if (res == 0) b.push_back(a[i + 1]), b.push_back(a[i + 3]);
				else if (res == 1) b.push_back(a[i]), b.push_back(a[i + 3]);
				else b.push_back(a[i + 1]), b.push_back(a[i + 2]);
			}
			a = b;
		}
		if (a.size() > 1) {
			vector <int> b;
			for (int i = 0; i < a.size(); i += 2) {
				printf("? %d %d\n", a[i], a[i + 1]);
				fflush(stdout);
				int res;
				scanf("%d", &res);
				if (res == 0) assert (false);
				else if (res == 1) b.push_back(a[i]);
				else b.push_back(a[i + 1]);
			}
			a = b;
		}
	}
	printf("! %d\n", a[0]);
	fflush(stdout);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}