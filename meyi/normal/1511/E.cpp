#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10,mod=998244353;
inline int qpow(int x,int y){
	int ret=1;
	for(;y;x=1ll*x*x%mod,y>>=1)if(y&1)ret=1ll*ret*x%mod;
	return ret;
}
int cnt,m,n,tmp1,tmp2[maxn];
char s[2][maxn];
ll ans[maxn],sum;
inline void add(int k){
	++k;
	for(ri i=k-1;i;--i)ans[k-i+1]+=i;
}
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i){
		ri now=i&1,pre=now^1;
		scanf("%s",s[now]+1);
		for(ri j=1;j<=m;++j)
			if(s[now][j]=='o'){
				++cnt;
				if(s[now][j-1]=='o')++tmp1;
				else if(tmp1)add(tmp1),tmp1=0;
				if(s[pre][j]=='o')++tmp2[j];
				else if(tmp2[j])add(tmp2[j]),tmp2[j]=0;
			}
			else{
				if(tmp1)add(tmp1),tmp1=0;
				if(tmp2[j])add(tmp2[j]),tmp2[j]=0;
			}
		if(tmp1)add(tmp1),tmp1=0;
	}
	for(ri j=1;j<=m;++j)if(tmp2[j])add(tmp2[j]),tmp2[j]=0;
	for(ri i=2;i<=cnt;++i)
		if(i&1)sum=((sum-ans[i]*qpow(2,cnt-i)%mod)%mod+mod)%mod;
		else sum=(sum+ans[i]*qpow(2,cnt-i)%mod)%mod;
	printf("%lld",sum);
	return 0;
}