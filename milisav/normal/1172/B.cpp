#include<bits/stdc++.h>
using namespace std;
long long fact[300000];
long long n;
vector<int> a[300000];
long long ch[300000];
bool o[300000];
long long mod=998244353;
void dfs(int u) {
	o[u]=true;
	int v;
	ch[u]=1;
	for(int i=0;i<a[u].size();i++) {
		v=a[u][i];
		if(!o[v]) {
			dfs(v);
			ch[u]+=ch[v];
		}
	}
	o[u]=false;
}
long long val(int u) {
	o[u]=true;
	int v;
	long long rt=1;
	int m=0;
	for(int i=0;i<a[u].size();i++) {
		v=a[u][i];
		if(!o[v]) {
			rt=(rt*val(v))%mod;
			m++;
		}
	}
	if(u==1) return (n*((fact[m]*rt)%mod))%mod;
	else return ((m+1)*((fact[m]*rt)%mod))%mod;
}
int main()
{
	scanf("%lld",&n);
	int u,v;
	for(int i=0;i<n-1;i++) {
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	fact[0]=1;
	for(long long i=1;i<=n;i++) fact[i]=(i*fact[i-1])%mod;
	dfs(1);
	printf("%lld",(val(1))%mod);
	return 0;
}