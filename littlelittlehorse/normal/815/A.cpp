#include<bits/stdc++.h>
using namespace std;
const int N(111);
int a[N][N], b[N][N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int mn(1e9), mni, mnj;
	for(int i(1); i <= n; i++) {
		for(int j(1); j <= m; j++) {
			scanf("%d", &a[i][j]);
			if(mn > a[i][j]) {
				mni = i; mnj = j;
				mn = a[i][j];
			}
		}
	}
	vector<int> r, c;
	for(int i(1); i <= mn; i++) {
		if(n < m) {
			for(int j(1); j <= n; j++) {
				r.push_back(j);
			}
		}else {
			for(int j(1); j <= m; j++) {
				c.push_back(j);
			}
		}
	}
	for(int i(1); i <= n; i++)
		if(i != mni)
			for(int j(0); j < a[i][mnj] - mn; j++)
				r.push_back(i);
	for(int i(1); i <= m; i++)
		if(i != mnj)
			for(int j(0); j < a[mni][i] - mn; j++)
				c.push_back(i);
	for(int i : c)
		for(int j(1); j <= n; j++)
			b[j][i]++;
	for(int i : r)
		for(int j(1); j <= m; j++)
			b[i][j]++;
	bool flag(1);
	for(int i(1); i <= n; i++)
		for(int j(1); j <= m; j++) {
			flag &= a[i][j] == b[i][j];
		}
	if(!flag) {
		printf("-1\n");
	}else {
		printf("%d\n", (int)r.size() + (int)c.size());
		for(int i : r) {
			printf("row %d\n", i);
		}
		for(int i : c) {
			printf("col %d\n", i);
		}
	}
}