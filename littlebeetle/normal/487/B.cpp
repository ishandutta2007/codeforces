#include<cstdio>
const int N=100002,K=19;
int n,s,l,i,j,a[N],f[N][K],g[N][K],Lg[N],L,R,F[N];
int D,t[N*4];
void init(){
	scanf("%d%d%d",&n,&s,&l);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),F[i]=1<<30;
	for(Lg[0]=-1,i=1;i<=n;i++)
		Lg[i]=Lg[i>>1]+1;
}
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
void pre(){
	for(i=1;i<=n;i++)
		f[i][0]=g[i][0]=a[i];
	for(j=0;(1<<j+1)<=n;j++)
		for(i=1;i+(1<<j+1)<=n+1;i++){
			f[i][j+1]=max(f[i][j],f[i+(1<<j)][j]);
			g[i][j+1]=min(g[i][j],g[i+(1<<j)][j]);
		}
	for(D=1;D<n+2;D<<=1);
	for(i=1;i<D;i++)
		t[i+D]=1<<30;
	for(i=D-1;i;i--)
		t[i]=min(t[i<<1],t[i<<1|1]);
}
int Max(int l,int r){
	int j=Lg[r-l+1];
	return max(f[l][j],f[r-(1<<j)+1][j]);
}
int Min(int l,int r){
	int j=Lg[r-l+1];
	return min(g[l][j],g[r-(1<<j)+1][j]);
}
int get(int x){
	int l=1,r=x,mid;
	while(l<r){
		mid=l+r>>1;
		if(Max(mid,x)-Min(mid,x)<=s)
			r=mid;
		else
			l=mid+1;
	}
	return r;
}
int Query(int x,int y){
	int s=1<<30;
	for(x+=D-1,y+=D+1;x^y^1;x>>=1,y>>=1){
		if(~x&1)s=min(s,t[x^1]);
		if(y&1)s=min(s,t[y^1]);
	}
	return s;
}
void Update(int x,int y){
	t[x+=D]=y;
	while(x>>=1)
		t[x]=min(t[x<<1],t[x<<1|1]);
}
void work(){
	for(i=l;i<=n;i++){
		L=get(i)-1;
		R=i-l;
		if(L<=R){
			F[i]=Query(L,R)+1;
			Update(i,F[i]);
		}
	}
	printf("%d",F[n]<(1<<30)?F[n]:-1);
}
int main(){
	init();
	pre();
	work();
	return 0;
}