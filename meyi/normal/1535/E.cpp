#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int lg=18,maxn=3e5+10;
int a[maxn],c[maxn],fa[maxn][lg+1],m,n,t_case;
int  main(){
	scanf("%d%d%d",&n,a+1,c+1);
	for(ri i=2;i<=n+1;++i){
		ri op,x,y;
		scanf("%d",&op);
		if(op&1){
			scanf("%d%d%d",fa+i,a+i,c+i);
			++fa[i][0];
			for(ri j=1;j<=lg;++j)fa[i][j]=fa[fa[i][j-1]][j-1];
		}
		else{
			scanf("%d%d",&x,&y);
			++x;
			ri z=y;
			ll sum=0;
			while(a[x]&&y){
				ri now=x;
				for(ri j=lg;~j;--j)
					if(a[fa[now][j]])
						now=fa[now][j];
				ll d=min(a[now],y);
				a[now]-=d,y-=d,sum+=c[now]*d;
			}
			printf("%d %lld\n",z-y,sum);
			fflush(stdout);
		}
	}
	return 0;
}