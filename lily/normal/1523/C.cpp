#include <bits/stdc++.h>
using namespace std;

const int N = 1011;
int n;
vector <int> a[N];
string ans[N];
void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		a[i].clear();
	}
	vector <int> cur;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 1) cur.push_back(x);
		else {
			while (cur.back() != x - 1) cur.pop_back();
			cur[cur.size() - 1] ++;
		}
		for (int i = 0; i < cur.size(); i++) {
			if (i) printf(".");
			printf("%d", cur[i]);
		}
		printf("\n");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();
}