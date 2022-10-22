#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=510;
int a[maxn][maxn],ans[maxn],b[maxn][maxn],c[maxn][2],d,e,m,n,t_case;
signed main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(ri i=0;i<10;++i){
		memset(c,0,sizeof c);
		for(ri j=1;j<=n;++j)
			for(ri k=1;k<=m;++k){
				b[j][k]=(a[j][k]>>i)&1;
				c[j][b[j][k]]=1;
			}
		d=0,e=0;
		for(ri j=1;j<=n;++j)d+=(c[j][0]&&!c[j][1]),e+=(c[j][0]&&c[j][1]);
		if(e){
			ri cur=0;
			for(ri j=1;j<=n;++j)
				if(!c[j][0]||!c[j][1])
					cur^=b[j][1],ans[j]=1;
			for(ri j=1;j<=n;++j)
				if(c[j][0]&&c[j][1])
					for(ri k=1;k<=m;++k)
						if(cur^b[j][k]){
							ans[j]=k;
							cur^=b[j][k];
							break;
						}
			goto output;
		}
		else if((d&1)!=(n&1)){
			for(ri j=1;j<=n;++j)ans[j]=1;
			goto output;
		}
	}
	puts("NIE");
	return 0;
	output:;
	puts("TAK");
	for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}