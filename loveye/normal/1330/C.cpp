#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define int long long
int n,m,sum,l[N],res,pos,ok = 1,ans[N];
signed main() {
	cin >> n >> m;
	for(int i = 1;i <= m;++i)
		cin >> l[i],sum += l[i];
	res = sum - n;
	for(int i = 1;i <= m;++i)
		if(i+l[i]-1 > n) ok = 0;
	if(sum < n || !ok) return puts("-1"),0;
	pos = 1;
	for(int i = 1;i <= m;++i) {
		ans[i] = pos;
		pos += l[i] - min(res,l[i]-1),res -= min(res,l[i]-1);
	}
	for(int i = 1;i < m;++i)
		printf("%lld ",ans[i]);
	printf("%lld\n",ans[m]);
	return 0;
}