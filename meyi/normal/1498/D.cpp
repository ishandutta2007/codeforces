#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
const double eps=1e-5;
int ans[maxn],cnt[maxn],m,n,t,y;
ll m1,x;
int main(){
	scanf("%d%d",&n,&m);
	m1=m*100000ll;
	for(ri i=1;i<=n;++i){
		scanf("%d%lld%d",&t,&x,&y);
		ans[0]=i;
		for(ri j=0;j<=m;++j)
			if(ans[j])
				cnt[j]=y;
		for(ll j=0;j<=m1;j+=100000){
			ri k=j/100000;
			if(!cnt[k])continue;
			ll to=(((t&1)?j+x:k*x)+99999)/100000;
			if(to>m)break;
			if(!ans[to])ans[to]=i,cnt[to]=cnt[k]-1;
		}
	}
	for(ri i=1;i<=m;++i)printf("%d ",ans[i]?ans[i]:-1);
	return 0;
}