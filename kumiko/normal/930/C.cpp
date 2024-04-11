#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

const int maxn = 100100;
int n, m;
int a[maxn], c[maxn], f[maxn];

int ask(int x){
	int res = 0;
	for(; x; x -= x & -x)
		res = max(res, c[x]);
	return res;
}

void modify(int x, int v){
	for(; x <= n; x += x & -x)
		c[x] = max(c[x], v);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		int l, r;
		scanf("%d%d", &l, &r);
		++a[l];
		--a[r + 1];
	}
	a[0] = 1;
	for(int i = 1; i <= m; ++i){
		a[i] += a[i - 1];
		f[i] = ask(a[i]) + 1;
		modify(a[i], f[i]);
	}
	memset(c, 0, sizeof(c));
	int ans = 0;
	for(int i = m; i >= 1; --i){
		int v = ask(a[i]) + 1;
		modify(a[i], v);
		v += f[i] - 1;
		ans = max(ans, v);
	}
	printf("%d\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}