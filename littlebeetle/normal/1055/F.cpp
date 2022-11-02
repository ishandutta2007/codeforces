#include<cstdio>
const int N=1000002;
int n,i,j,p,ch[N][2],a[N],b[N],sz[N],cnt;
long long k,s,v[N],ans,t;
void init(){
	scanf("%d%lld",&n,&k);
	for(i=2;i<=n;i++){
		scanf("%d%lld",&p,v+i);
		v[i]^=v[p];
	}
}
int Gtch(int x,int y){
	return ch[x][y]?ch[x][y]:ch[x][y]=++cnt;
}
void work(){
	for(i=1;i<=n;i++)
		a[i]=b[i]=1;
	for(j=62;j>=0;j--){
		s=0;cnt=0;t=0;
		for(i=1;i<=n;i++)
			ch[i][0]=ch[i][1]=sz[i]=0;
		for(i=1;i<=n;i++)
			sz[a[i]=Gtch(a[i],v[i]>>j&1)]++;
		for(i=1;i<=n;i++)
			s+=sz[ch[b[i]][v[i]>>j&1]];
		if(s<k)
			ans+=1ll<<j,k-=s,t=1;
		for(i=1;i<=n;i++)
			b[i]=ch[b[i]][v[i]>>j&1^t];	
	}
	printf("%lld",ans);
}
int main(){
	init();
	work();
	return 0;
}