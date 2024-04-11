#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=410;
int m,n,sum[maxn][maxn],t_case;
char s[maxn][maxn];
inline int getsum1(int x,int y,int xx,int yy){
	return sum[xx][yy]-sum[x-1][yy]-sum[xx][y-1]+sum[x-1][y-1];
}
inline int getsum0(int x,int y,int xx,int yy){
	return (xx-x+1)*(yy-y+1)-getsum1(x,y,xx,yy);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=m;++j)
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]^48);
		ri ans=16;
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=m;++j)
				for(ri k=i+4;k<=n;++k)
					for(ri l=j+3;l<=m;++l){
						ri req1=getsum0(i,j+1,i,l-1)+getsum0(i+1,j,k-1,j)+getsum0(k,j+1,k,l-1)+getsum1(i+1,j+1,k-1,l-1);
						if(req1>=ans)break;
						ri req2=getsum0(i+1,l,k-1,l);
						ckmin(ans,req1+req2);
					}
		printf("%d\n",ans);
	}
	return 0;
}