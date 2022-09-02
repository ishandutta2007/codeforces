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

int A[100], C[100];

int st[220], en[20020], nxt[20020], cost[20020], flow[20020], ce = 1;
void addE(int s, int e, int c, int f) {
	++ce; nxt[ce] = st[s]; st[s] = ce; en[ce] = e; cost[ce] = c; flow[ce] = f;
	++ce; nxt[ce] = st[e]; st[e] = ce; en[ce] = s; cost[ce] = -c; flow[ce] = 0;
}

int N, K;
int ST, EN;

int inq[200], dis[200], pre[200];
int spfa() {
	for (int i = 1; i <= EN; i++) dis[i] = 1e9;
	dis[ST] = 0;
	queue <int> que; que.push(ST); inq[ST] = 1;
	while (!que.empty()) {
		int t = que.front(); que.pop();
		inq[t] = 0;
		for (int i = st[t]; i; i = nxt[i]) if(flow[i] > 0) {
			if (dis[en[i]] > dis[t] + cost[i]) {
				dis[en[i]] = dis[t] + cost[i];
				pre[en[i]] = i;
				if (inq[en[i]] == 0) {
					inq[en[i]] = 1;
					que.push(en[i]);
				}
			}
		}
	}
	if (dis[EN] == 1e9) return dis[EN];
	int t = EN;
	while (t != ST) {
		int p = pre[t];
		flow[p]--;
		flow[p ^ 1]++;
		t = en[p ^ 1];
	}
	return dis[EN];
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d", A + i);
	for (int i = 1; i <= N; i++) scanf("%d", C + i);
	int prev[100] = {}, now[100] = {};
	for (int i = 1; i <= N; i++)now[i] = -1;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		prev[i] = now[A[i]];
		now[A[i]] = i;
	}
	for (int i = 1; i <= N; i++) {
		if (prev[i] != i - 1) ans += C[A[i]];
	}
	for (int i = 1; i <= N; i++) {
		addE(i, i + 1, 0, K - 1);
	}
	int CC = N + 1;
	ST = ++CC;
	for (int i = 1; i <= N; i++) if (prev[i] != -1 && prev[i] != i - 1) {
		addE(ST, prev[i] + 1, 0, 1);
		addE(prev[i] + 1, ++CC, 0, 1);
		addE(i, CC, -C[A[i]], 1);
	}
	EN = ++CC;
	for (int i = ST + 1; i < EN; i++) {
		addE(i, EN, 0, 1);
	}
	while (1) {
		int t = spfa();
		if (t == 1e9) break;
		ans += t;
	}
	printf("%d\n", ans);
	return 0;
}