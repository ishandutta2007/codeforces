#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5,MOD = 1e9 + 7;
#define LL long long
int n,m,k,c[10],to[N];
int f[N];
vector<int> ans;
inline LL qpow(LL a,int x) {
	LL res = 1;
	for(;x;x >>= 1) (x & 1) && (res = res * a % MOD),a = a * a % MOD;
	return res;
}
int getf(int x) {
	return f[x] == x ? x : f[x] = getf(f[x]);
}
inline int Insert() {
	if(c[1] > c[2]) swap(c[1],c[2]);
	while(to[c[1]] && c[1] != c[2]) {
		c[1] = getf(c[1]);
		if(c[1] > c[2]) swap(c[1],c[2]);
	}
	if(c[1] == c[2]) return 0;
	to[c[1]] = c[2];
	f[c[1]] = c[2];
	return 1;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m+1;++i)
		f[i] = i;
	for(int i = 1;i <= n;++i) {
		scanf("%d",&k);
		for(int j = 1;j <= k;++j)
			scanf("%d",c+j);
		if(k == 1) c[++k] = m+1;
		if(Insert()) ans.push_back(i);
	}
	printf("%I64d %d\n",qpow(2,ans.size()),ans.size());
	for(int i = 0;i < ans.size();++i)
		printf("%d ",ans[i]);
	return 0;
}