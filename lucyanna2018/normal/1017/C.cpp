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
int n;
vector<int> v;
int main() {
	scanf("%d", &n);
	int m = (int)sqrt(n + .5);
	for (int i = 0; i < m; i++)
		v.push_back(m);
	n -= m * m;
	for (int i = 0; i < m; i++) {
		if (n == 0)break;
		n--;
		v[i] ++;
	}
	if (n > 0)v.push_back(n);
	n = 0;
	bool ff = false;
	for (auto x : v) {
		n += x;
		for (int i = 0; i < x; i++) {
			if (ff)printf(" ");ff = true;
			printf("%d", n - i);
		}
	}
	puts("");
	return 0;
}