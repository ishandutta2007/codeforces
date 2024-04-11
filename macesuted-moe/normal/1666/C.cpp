#include<bits/stdc++.h>
using namespace std;
struct apple{
	int x,y,xx,yy;
	apple(int x=0,int y=0,int xx=0,int yy=0):
		x(x),y(y),xx(xx),yy(yy){}
}e[10005];
int x[4],y[4];
int xx[400],yy[400];
bitset<25>bs[25];
bool zaishang(int a,int b){
	if(e[b].x==e[b].xx){
		if(xx[a]!=e[b].x)return 0;
		if(1ll*(yy[a]-e[b].y)*(yy[a]-e[b].yy)>0)return 0;
		return 1;
	}
	if(e[b].y==e[b].yy){
		if(yy[a]!=e[b].y)return 0;
		if(1ll*(xx[a]-e[b].x)*(xx[a]-e[b].xx)>0)return 0;
		return 1;
	}
	return 0;
}
int aa[5];
int main(){
	int n=3;
	for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
	int m=0;
	for(int i=1;i<n;++i)for(int j=i+1;j<=n;++j){
		if(x[i]!=x[j]){
			e[++m]=apple(x[i],y[i],x[j],y[i]);
			if(y[i]!=y[j])e[++m]=apple(x[i],y[j],x[j],y[j]);
		}
		if(y[i]!=y[j]){
			e[++m]=apple(x[i],y[i],x[i],y[j]);
			if(y[i]!=y[j])e[++m]=apple(x[j],y[i],x[j],y[j]);
		}
	}
	int N=0;
	for(int i=1;i<=m;++i){
		++N;
		xx[N]=e[i].x,yy[N]=e[i].y;
		++N;
		xx[N]=e[i].xx,yy[N]=e[i].yy;
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=N;++j)
		if(x[i]==xx[j]&&y[i]==yy[j])aa[i]=j;
	long long ans=LLONG_MAX;
	int fa=-1;
	for(int i=0;i<(1<<m);++i){
		for(int j=1;j<=N;++j)bs[j].reset();
		for(int j=1;j<=N;++j)bs[j][j]=1;
		for(int j=1;j<=N;++j)for(int k=1;k<=N;++k)
			for(int l=1;l<=m;++l)if(i&(1<<(l-1))){
				if(zaishang(j,l)&&zaishang(k,l))bs[j][k]=1;
			}
		for(int k=1;k<=N;++k)for(int i=1;i<=N;++i)
			if(bs[i][k])bs[i]|=bs[k];
		int flag=1;
		for(int j=1;j<n;++j)for(int k=j+1;k<=n;++k){
			if(!bs[aa[j]][aa[k]])flag=0;
		}
		if(flag){
			long long he=0;
			for(int l=1;l<=m;++l)if(i&(1<<(l-1))){
				he+=abs(e[l].x-e[l].xx)+abs(e[l].y-e[l].yy);
			}
			if(ans>he)ans=he,fa=i;
		}
	}
	assert(~fa);
	printf("%d\n",(signed)__builtin_popcount(fa));
	for(int i=1;i<=m;++i)if(fa&(1<<(i-1))){
		printf("%d %d %d %d\n",e[i].x,e[i].y,e[i].xx,e[i].yy);
	}
	return 0;
}