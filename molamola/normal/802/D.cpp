#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1E-11;

const int MX = 100005;

void Do() {
	int A[255] = {};
	rep(i, 250) scanf("%d", A + i);
	double avg = 0;
	rep(i, 250) avg += A[i];
	avg /= 250.0;
	int cnt = 0;
	for (int i = 0; i < 250; i++) {
		double X = (double)A[i] / avg;
		if (0.5 <= X && X <= 1.5) ++cnt;
	}
	double C = cnt / 250.0;
	if (C > 0.7) puts("poisson");
	else puts("uniform");
}

int main() {
	int V; scanf("%d", &V);
	while (V--) {
		Do();
	}
	return 0;
}