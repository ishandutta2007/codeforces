#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

const double lg = 0.63092975357145743709952711434276;
const int mod = inf + 7;

bool f(double a, double b) {
	return a > b * lg;
}

bool f(vec< int > a, vec< int > b) {
	for(int x, i = 0;i < 2;i++) {
		x = min(a[i], b[i]);
		a[i] -= x;
		b[i] -= x;
	}

	if(*max_element(ALL(a)) == 0) return 0;
	if(*max_element(ALL(b)) == 0) return 1;

	int v1, v2;
	
	v1 = a[0] == 0? 3 : 2;
	v2 = b[0] == 0? 3 : 2;

	if(v1 == 3) return f(a[1], b[0]);
	else return !f(b[1], a[0]);
}

vec< vec< int > > d1, d2;
vec< vec< int > > s11, s12, s21, s22; 

int get(int i1, int j1, int i2, int j2, const vec< vec< int > > & S) {
	return S[i2][j2] - (j1?S[i2][j1 - 1] : 0) - (i1?S[i1 - 1][j2] : 0) + (i1 && j1?S[i1 - 1][j1 - 1] : 0);
}

int n;

int got(int diag, int l, int r, const vec< vec< int > > & S) {
	return S[diag][r] - (l?S[diag][l - 1] : 0);
}

bool solve() {
	
	scanf("%d", &n);

	vec< vec< int > > a(n, vec< int >(n));

	int ok = 0;

	for(int i = 0;i < n;i++) {
		char c;
		for(int j = 0;j < n;j++) {
			scanf(" %c", &c);
			a[i][j] = c - '0';
			if(c > '0') ok = 1;
		}
	}

	if(!ok) {
		printf("0\n");
		return true;
	}

	vec< int > res(2), tmp(2);

	vec< vec< int  > > 
		l(n,  vec< int >(n)), 
		r(n,  vec< int >(n)), 
		d(n,  vec< int >(n)), 
		u(n,  vec< int >(n)),
		lu(n, vec< int >(n)),
		ru(n, vec< int >(n)), 
		ld(n, vec< int >(n)),
		rd(n, vec< int >(n));

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(a[i][j] == 0) l[i][j] = 0; else l[i][j] = (j?l[i][j - 1] : 0) + 1;
			if(a[j][i] == 0) u[j][i] = 0; else u[j][i] = (j?u[j - 1][i] : 0) + 1;
		}
		for(int j = n - 1;j >= 0;j--) {
			if(a[i][j] == 0) r[i][j] = 0; else r[i][j] = (j + 1 < n?r[i][j + 1] : 0) + 1;
			if(a[j][i] == 0) d[j][i] = 0; else d[j][i] = (j + 1 < n?d[j + 1][i] : 0) + 1;
		}
	}

	for(int j = 0;j < n;j++) {
		for(int i = 0;i < n;i++) {
			if(a[i][j] == 0) lu[i][j] = ld[i][j] = 0;
			else {
				lu[i][j] = (i > 0 && j > 0?lu[i - 1][j - 1] : 0) + 1;
				ld[i][j] = (i + 1 < n && j > 0?ld[i + 1][j - 1] : 0) + 1;
			}
		}
	}

	for(int j = n - 1;j >= 0;j--) {
		for(int i = 0;i < n;i++) {
			if(a[i][j] == 0) ru[i][j] = rd[i][j] = 0;
			else {
				ru[i][j] = (i > 0 && j + 1 < n?ru[i - 1][j + 1] : 0) + 1;
				rd[i][j] = (i + 1 < n && j + 1 < n?rd[i + 1][j + 1] : 0) + 1;
			}
		}
	}

	d1 = d2 = vec< vec< int > >(n, vec< int >(n)); 

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			d1[i][j] = (i?d1[i - 1][j] : 0) + (j?d1[i][j - 1] : 0) - (i && j?d1[i - 1][j - 1] : 0) + (a[i][j] == 2);
			d2[i][j] = (i?d2[i - 1][j] : 0) + (j?d2[i][j - 1] : 0) - (i && j?d2[i - 1][j - 1] : 0) + (a[i][j] == 3);
		}
	}

	s11 = s12 = s21 = s22 = vec< vec< int > >(n + n, vec< int>(n));

	for(int j = 0;j < n;j++) {
		for(int i = 0;i < n;i++) {
			s11[i + j][j] = (j?s11[i + j][j - 1] : 0) + (a[i][j] == 2);
			s12[i + j][j] = (j?s12[i + j][j - 1] : 0) + (a[i][j] == 3);
			int diag = i + n - 1 - j;
			s21[diag][j] = (j?s21[diag][j - 1] : 0) + (a[i][j] == 2);
			s22[diag][j] = (j?s22[diag][j - 1] : 0) + (a[i][j] == 3);
		}
	}

	for(int i = 0;i < n;i++) {
		for(int I, J, dist, j = 0;j < n;j++) {
			if(a[i][j] == 0) {
				continue;
			}

			dist = min(min(l[i][j], r[i][j]), min(u[i][j], d[i][j]));
			tmp[0] = get(i, j - dist + 1, i, j + dist - 1, d1) +  get(i - dist + 1, j, i + dist - 1, j, d1) - (a[i][j] == 2);
			tmp[1] = get(i, j - dist + 1, i, j + dist - 1, d2) +  get(i - dist + 1, j, i + dist - 1, j, d2) - (a[i][j] == 3);

			if(f(tmp, res)) res = tmp;

			I = i + j;
			J = i + n - 1 - j;

			dist = min(min(lu[i][j], ld[i][j]), min(ru[i][j], rd[i][j]));
			tmp[0] = got(I, j - dist + 1, j + dist - 1, s11) + 
					 got(J, j - dist + 1, j + dist - 1, s21) - (a[i][j] == 2);
			tmp[1] = got(I, j - dist + 1, j + dist - 1, s12) + 
					 got(J, j - dist + 1, j + dist - 1, s22) - (a[i][j] == 3);

			if(f(tmp, res)) res = tmp;

		}

	}

	int val = 1;
	
	for(int x = 2;x <= 3;x++) {
		for(int i = 0;i < res[x - 2];i++) {
			val = (1ll * val * x) % mod;
		}
	}

	printf("%d\n", val);

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}