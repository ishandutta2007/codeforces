#include<cstdio>
#include<cstring>
const int MAXN=5e4+5,MAXMUL=4e5+5,INF=0x7fffffff;
inline int maxx(int a,int b){
	if(a>b) return a;
	return b;
}
inline int minn(int a,int b){
	if(a<b) return a;
	return b;
}
int q,n,m;
int sumr[MAXN],sumc[MAXN];
char s[MAXMUL];
int ans;
int main(){
//	freopen("B.out","w",stdout);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&m);
		memset(sumr,0,sizeof(sumr));
		memset(sumc,0,sizeof(sumc));
		for(int i=1;i<=n;i++){
			scanf("%s",s+((i-1)*m)+1);
			for(int j=1;j<=m;j++)
				if(s[(i-1)*m+j]=='*') sumr[i]++,sumc[j]++;
		}
		ans=INF;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans=minn(ans,n+m-sumr[i]-sumc[j]+(s[(i-1)*m+j]=='*'?0:-1));
		printf("%d\n",ans);
	}
	return 0;
}