#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxk=21,maxn=1e5+10;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int a[maxn],cnt[maxn],k,n,pl=1,pr;
ll f[maxk][maxn],sum;
inline void add(int k){
	sum+=cnt[k];
	++cnt[k];
}
inline void del(int k){
	--cnt[k];
	sum-=cnt[k];
}
inline ll calc(int l,int r){
	while(pl<l)del(a[pl++]);
	while(pl>l)add(a[--pl]);
	while(pr<r)add(a[++pr]);
	while(pr>r)del(a[pr--]);
	return sum;
}
void solve(int l,int r,int L,int R,int now){
	if(l>r||L>R)return;
	ri mid=l+r>>1,pos=0;
	ll val=LLONG_MAX;
	for(ri i=L;i<=R&&i<mid;++i){
		ll tmp=f[now-1][i]+calc(i+1,mid);
		if(tmp<val)pos=i,val=tmp;
	}
	f[now][mid]=val;
	solve(l,mid-1,L,pos,now);
	solve(mid+1,r,pos,R,now);
}
int main(){
	scanf("%d%d",&n,&k);
	for(ri i=1;i<=n;++i)f[0][i]=inf,scanf("%d",a+i);
	for(ri i=1;i<=k;++i)solve(1,n,0,n,i);
	printf("%lld",f[k][n]);
	return 0;
}