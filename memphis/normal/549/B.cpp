#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
#include<set>
#include<vector>
//#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
typedef long double ld;
const int P=1000000007;
const int N=105;

int n,a[N],deg[N],lim,c[N],p[N][N],len[N],u[N],v[N];
bool g[N][N],f[N];
char s[N][N];

int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%s",s[i]+1);
	//return 0;
	rep(i,1,n) rep(j,1,n){
		g[i][j]=s[i][j]=='1';
		if(g[i][j]) p[i][++len[i]]=j;
	}
	//return 0;
	rep(i,1,n) scanf("%d",a+i);
	lim=10000;
	rep(i,1,n) c[i]=i;
	while(lim--){
		random_shuffle(c+1,c+1+n);
		bool flag=1;
		rep(i,1,n)
			if(deg[c[i]]==a[c[i]]){
				//printf("%d\n",c[i]);
				flag=0;
				*u=0;
				*v=0;
				rep(j,1,len[c[i]])
					if(f[p[c[i]][j]]) u[++*u]=p[c[i]][j];
					else v[++*v]=p[c[i]][j];
				int z;
				if(*u==0) z=1;
				else if(*v==0) z=0;
				else z=rand()&1;
				//return 0;
				//printf("%d %d\n",*u,*v);
				//return 0;
				if(!z) z=u[rand()%(*u)+1];
				else z=v[rand()%(*v)+1];
				int aim=0;
				//printf("%d\n",z);
				//return 0;
				if(f[z]) aim=-1;
				else aim=1;
				f[z]^=1;
				rep(j,1,len[z]) deg[p[z][j]]+=aim;
				//return 0;
			}
		//rep(i,1,n) printf("%d ",f[i]);
		//puts("");
		if(flag){
			int cnt=0;
			rep(i,1,n) if(f[i]) ++cnt;
			printf("%d\n",cnt);
			rep(i,1,n) if(f[i]) printf("%d ",i);
			return 0;
		}
	}
	puts("-1");
}