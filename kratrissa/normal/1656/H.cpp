#include<bits/stdc++.h>
using namespace std;
const int N=1005;
typedef __int128 lll;
template<typename T> void read(T &a){
	a=0;char c=getchar();
	while(c<48)c=getchar();
	while(c>=48)a=a*10+c-48,c=getchar();
}
template<typename T> void print(T a){
	char ch[50];int h=0;
	while(a)ch[h++]=a%10+48,a/=10;
	while(h--)putchar(ch[h]);putchar(' ');
}
int T,n,m;lll a[2][N],st[2][N][N<<2];bool ok[2][N];
lll gcd(lll x,lll y){return x==0?y:gcd(y%x,x);}
lll lcm(lll x,lll y){return x/gcd(x,y)*y;}
void build(bool t,int p,int l,int r,int x){
	if(l==r){st[t][p][x]=gcd(a[t][p],a[t^1][l]);return;}
	int mid=l+r>>1;
	build(t,p,l,mid,x<<1),build(t,p,mid+1,r,x<<1|1),st[t][p][x]=lcm(st[t][p][x<<1],st[t][p][x<<1|1]);
}
void modify(bool t,int p,int l,int r,int x,int v){
	if(l==r){st[t][p][x]=1;return;}
	int mid=l+r>>1;
	if(v<=mid)modify(t,p,l,mid,x<<1,v);
	else modify(t,p,mid+1,r,x<<1|1,v);
	st[t][p][x]=lcm(st[t][p][x<<1],st[t][p][x<<1|1]);
}
int main(){
	read(T);
	while(T--){
		read(n),read(m),fill(ok[0],ok[0]+n+1,1),fill(ok[1],ok[1]+m+1,1);
		for(int i=1;i<=n;i++)read(a[0][i]);
		for(int i=1;i<=m;i++)read(a[1][i]);
		for(int i=1;i<=n;i++)build(0,i,1,m,1);
		for(int i=1;i<=m;i++)build(1,i,1,n,1);
		bool t;int p;
		while(1){
			t=p=0;
			for(int i=1;i<=n;i++)if(st[0][i][1]!=a[0][i]&&ok[0][i]){t=0,p=i;break;}
			for(int i=1;i<=m;i++)if(st[1][i][1]!=a[1][i]&&ok[1][i]){t=1,p=i;break;}
			if(!p)break;
			ok[t][p]=0;
			if(t==0){for(int i=1;i<=m;i++)modify(1,i,1,n,1,p);}
			else{for(int i=1;i<=n;i++)modify(0,i,1,m,1,p);}
		}
		int s0=0,s1=0;
		for(int i=1;i<=n;i++)s0+=ok[0][i];
		for(int i=1;i<=m;i++)s1+=ok[1][i];
		if(!s0||!s1){printf("NO\n");continue;}
		printf("YES\n%d %d\n",s0,s1);
		for(int i=1;i<=n;i++)if(ok[0][i])print(a[0][i]);printf("\n");
		for(int i=1;i<=m;i++)if(ok[1][i])print(a[1][i]);printf("\n");
	}
	return 0;
}