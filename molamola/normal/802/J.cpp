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

void get_possion(int P, vector <int> &res) {
	
}

int n;
vector <pii> E[110];

int main() {
	scanf("%d", &n);
	rep(i, n - 1) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		E[x].push_back(pii(c, y));
		E[y].push_back(pii(c, x));
	}
	int dis[110] = {};
	for (int i = 0; i < n; i++) dis[i] = -1;
	dis[0] = 0;
	queue <int> que;
	que.push(0);
	while (!que.empty()) {
		int t = que.front(); que.pop();
		for (pii e : E[t]) if (dis[e.second] == -1) {
			dis[e.second] = dis[t] + e.first;
			que.push(e.second);
		}
	}
	printf("%d\n", *max_element(dis, dis + n));
	return 0;
}