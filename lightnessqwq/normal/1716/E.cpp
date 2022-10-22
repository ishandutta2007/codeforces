#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=1<<18,maxt=maxn<<2;
int n,m,V,T;
int a[maxn];
long long sum[maxt];
vector<long long>p[maxt],s[maxt],mx[maxt];
void solve(int l,int r,int now){
	int len=r-l+1;
	p[now].resize(len),s[now].resize(len),mx[now].resize(len);
	if(l==r){
		p[now][0]=s[now][0]=mx[now][0]=max(a[l],0),sum[now]=a[l];
		return ;
	}
	int mid=(l+r)>>1,lc=now<<1,rc=now<<1|1;
	solve(l,mid,lc),solve(mid+1,r,rc),sum[now]=sum[lc]+sum[rc];
	for(int i=0;i<len/2;i++){
		p[now][i]=max(p[lc][i],sum[lc]+p[rc][i]);
		s[now][i]=max(s[rc][i],sum[rc]+s[lc][i]);
		mx[now][i]=max(max(mx[lc][i],mx[rc][i]),s[lc][i]+p[rc][i]);
		p[now][len/2+i]=max(p[rc][i],sum[rc]+p[lc][i]);
		s[now][len/2+i]=max(s[lc][i],sum[lc]+s[rc][i]);
		mx[now][len/2+i]=max(max(mx[lc][i],mx[rc][i]),s[rc][i]+p[lc][i]);
	}
}
int main(){
	scanf("%d",&n),m=1<<n;
	for(int i=0;i<m;i++)
		scanf("%d",&a[i]);
	solve(0,m-1,1);
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x),V^=(1<<x),printf("%lld\n",mx[1][V]);
	}
	return 0;
}