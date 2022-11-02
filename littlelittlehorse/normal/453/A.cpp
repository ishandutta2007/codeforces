#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
double ans;

double rp(double now, int k){
	double will = 1;
	for (; k; k >>= 1, now *= now)
		if (k & 1) will *= now;
	return will;
}

int main(){
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	scanf("%d%d", &m, &n);
	ans = m;
	for (int i = 1; i < m; i++) ans -= rp(1.0 * i / m, n);
	printf("%.10lf\n", ans);
}