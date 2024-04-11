#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define i64 long long int
const int mo = 17;
int dv(i64 x) {
	x %= mo;
	return x < 0 ? x + mo : x;
}
int n, x[2022], y[2022];
i64 S;int smo;
const int Z = 50000000;
vector<int> a[mo * mo];
vector<int> b[mo * mo][mo * mo];
bool test(int i,int j,int k) {
	i64 i1 = x[i], j1 = y[i];
	i64 i2 = x[j], j2 = y[j];
	i64 i3 = x[k], j3 = y[k];
	return i1 * j2 + i2 * j3 + i3 * j1 - j1 * i2 - j2 * i3 - j3 * i1 == S;
}
int main() {
	cin >> n >> S; S *= 2;
	smo = dv(S);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		a[dv(x[i]) * mo + dv(y[i])].push_back(i);
	}
	for(int i1=0; i1<mo; i1++)
	for(int j1=0; j1<mo; j1++)
	for(int i2 = 0; i2<mo; i2++)
	for(int j2 = 0; j2<mo; j2++)
	for(int i3 = 0; i3<mo; i3++)
	for(int j3 = 0; j3<mo; j3++)
		if (dv(i1 * j2 + i2 * j3 + i3 * j1 - j1 * i2 - j2 * i3 - j3 * i1) == smo) {
			b[i1 * mo + j1][i2 * mo + j2].push_back(i3 * mo + j3);
		}
	for (int i = n - 1; i >= 0; i--) {
		int hi = dv(x[i]) * mo + dv(y[i]);
		a[hi].pop_back();
		int T = 0;
		for (int j = i - 1; j >= 0; j--) {
			int hj = dv(x[j]) * mo + dv(y[j]);
			for (vector<int>::iterator it = b[hi][hj].begin(); it != b[hi][hj].end(); it++) {
				for (vector<int>::iterator it2 = a[*it].begin(); it2 != a[*it].end(); it2++) {
					if (test(i, j, *it2)) {
						printf("Yes\n");
						printf("%d %d\n", x[i], y[i]);
						printf("%d %d\n", x[j], y[j]);
						printf("%d %d\n", x[*it2], y[*it2]);
						return 0;
					}
					++T;
					if (T >= Z)break;
				}
				if (T >= Z)break;
			}
			if (T >= Z)break;
		}
	}
	puts("No");
	return 0;
}