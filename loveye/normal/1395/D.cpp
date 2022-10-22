#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &

const int N = 1e5 + 5;
#define int long long
int a[N],n,d,m;
LL ans,sum[N];
signed main() {
	ios::sync_with_stdio(0);
	cin >> n >> d >> m;
	for(int i = 1;i <= n;++i)
		cin >> a[i];
	sort(a+1,a+n+1);
	int pos = 0;
	for(int i = 1;i <= n;++i) {
		sum[i] = sum[i-1] + a[i];
		if(a[i] <= m) pos = i;
	}
	for(int i = 0;i <= n-pos;++i) {
		int need = (i-1) * (d+1) + 1,rest = n-need;
		if(need > n) break;
		ans = max(ans,sum[n] - sum[n-i] + (rest <= pos ? sum[pos] - sum[pos-rest] : sum[pos]));
	}
	cout << ans << endl;
	return 0;
}