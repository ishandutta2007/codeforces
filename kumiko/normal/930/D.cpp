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
int n;
int x[maxn], y[maxn];
int id[maxn];
bool ok[maxn];
int l[maxn], r[maxn];
ll ans;

void work(bool k){
	memset(ok, 0, sizeof(ok));
	int L = 1e9, R = -1e9;
	for(int i = 1; i <= n; ++i){
		int xx = x[id[i]], yy = y[id[i]];
		if((abs(xx + yy) & 1) != k) continue;
		ok[i] = 1;
		L = min(L, yy - xx), R = max(R, yy - xx);
		l[i] = L, r[i] = R;
	}
	L = 1e9, R = -1e9;
	for(int i = n; i >= 1; --i){
		int xx = x[id[i]], yy = y[id[i]];
		if(!ok[i]) continue;
		L = min(L, yy - xx), R = max(R, yy - xx);
		int j = i - 1;
		while(!ok[j] && j) --j;
		if(!ok[j]) break;

		int tmp1 = (xx + yy - x[id[j]] - y[id[j]]) / 2;
		r[j] = min(r[j], R), l[j] = max(l[j], L);
		if(l[j] >= r[j]) continue;
		int tmp2 = (r[j] - l[j]) / 2;
		ans += (ll)tmp1 * tmp2;
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", x + i, y + i);
		id[i] = i;
	}
	sort(id + 1, id + n + 1, [](const int i, const int j){
			return x[i] + y[i] < x[j] + y[j];
		});
	work(0);
	work(1);
	printf("%I64d\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}