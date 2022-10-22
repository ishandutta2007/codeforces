#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int inf=0x3f3f3f3f,maxk=110,maxn=35e4+10;
int a[maxn],cnt,f[maxn][maxk],lst[maxn],m,n,nxt[maxn],pl=1,pre[maxn],pr,vis[maxn],sum;
inline int calc(int l,int r){
	while(pl<l){
		if(nxt[pl]<=pr)sum-=nxt[pl]-pl;
		++pl;
	}
	while(pl>l){
		--pl;
		if(nxt[pl]<=pr)sum+=nxt[pl]-pl;
	}
	while(pr<r){
		++pr;
		if(pre[pr]>=pl)sum+=pr-pre[pr];
	}
	while(pr>r){
		if(pre[pr]>=pl)sum-=pr-pre[pr];
		--pr;
	}
	return sum;
}
void solve(int l,int r,int L,int R,int now){
	if(l>r||L>R)return;
	ri mid=l+r>>1,val=inf,pos;
	for(ri i=L;i<mid&&i<=R;++i){
		ri tmp=f[i][now-1]+calc(i+1,mid);
		if(tmp<val)pos=i,val=tmp;
	}
	f[mid][now]=val;
	solve(l,mid-1,L,pos,now);
	solve(mid+1,r,pos,R,now);
}
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<=n;++i)f[i][0]=inf,pre[i]=lst[a[i]],lst[a[i]]=i;
	for(ri i=1;i<=n;++i)lst[a[i]]=n+1;
	for(ri i=n;i;--i)nxt[i]=lst[a[i]],lst[a[i]]=i;
	for(ri i=1;i<=m;++i)solve(1,n,0,n,i);
	printf("%d",f[n][m]);
	return 0;
}