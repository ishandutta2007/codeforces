#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 505
int n,m,i,j,k,x,y,cnt=0;
int a[N][N]={0},d[N]={0};
int c[N]={0};
int fa[N],sz[N];
int lst[N];
void er(){
	printf("No");
	exit(0);
}
int father(int x){
	if(fa[x]!=x) fa[x]=father(fa[x]);
	return fa[x];
}
int checkr(int x){
	rpt(j,1,cnt) if(lst[j]==x) return j;
	return 0;
}
void cn(int x,int y){
	int u=father(x),v=father(y);
	if(u==v) return;
	fa[u]=v;sz[v]+=sz[u];
}
void input(){
	scanf("%d%d",&n,&m);
	rpt(i,1,m){
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
		d[x]++;d[y]++;
	}
}
void init(){
	rpt(i,1,n) if(d[i]==n-1){
		c[i]=1;
	}
	rpt(i,1,n) if(c[i]==1){
		rpt(j,1,n) if(a[i][j]){
			a[i][j]=a[j][i]=0;
			d[j]--;
		}
	}
	rpt(i,1,n) fa[i]=i,sz[i]=1;
	rpt(i,1,n) rpt(j,1,n) if(a[i][j]) cn(i,j);
}
void work(){
	rpt(i,1,n) fa[i]=father(i);
	rpt(i,1,n) if(c[i]!=1) if(checkr(fa[i])==0){
		cnt++;
		lst[cnt]=fa[i];
	}
	if(cnt>2) er();
	rpt(i,1,n) if(c[i]!=1) if(d[i]!=sz[fa[i]]-1) er();
	rpt(i,1,n) if(c[i]!=1) c[i]=(checkr(fa[i])-1)*2;
}
void output(){
	printf("Yes\n");
	rpt(i,1,n) printf("%c",'a'+c[i]);
}
int main(){
	input();
	init();
	work();
	output();
	return 0;
}