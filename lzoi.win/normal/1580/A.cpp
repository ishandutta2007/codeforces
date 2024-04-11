#include<cstdio>
#include<cstring>
const int N=405;
int n,m,num[N][N],T;
int sum[N],suml[N],sumh1[N],sumh2[N],ans;
inline void Init(){
	scanf("%d %d",&n,&m);
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=m;j++)
			scanf("%1d",&num[i][j]);
	return ;
}
inline int cost(const int ll,const int rr,const int up,const int down){
	int len=down-up+1;
	int ss=0;
	ss+=suml[rr]+suml[ll];
	ss+=sumh1[rr-1]-sumh1[ll];
	ss+=sumh2[rr-1]-sumh2[ll];
	ss+=sum[rr-1]-sum[ll];
	return ss;
}
//suml[ll]-sumh1[ll]-sumh2[ll]-sum[ll]
inline int Min(const int x,const int y){
	return x<y?x:y;
}
inline void Solve(){
	ans=2147483647;
	for(register int up=1;up+4<=n;up++){
		memset(sum,0,sizeof(sum));
		memset(suml,0,sizeof(suml));
		for(register int j=1;j<=m;j++)
			sumh1[j]=sumh1[j-1]+(num[up][j]==0);
		for(register int down=up+1;down<=n;down++){
			for(register int j=1;j<=m;j++)
				sumh2[j]=sumh2[j-1]+(num[down][j]==0);
			if(down>=up+4){
				int ss=2147483647;
				for(register int rr=4;rr<=m;rr++){
					int ll=rr-3;
					ss=Min(ss,suml[ll]-sumh1[ll]-sumh2[ll]-sum[ll]);
					ans=Min(ans,suml[rr]+sumh1[rr-1]+sumh2[rr-1]+sum[rr-1]+ss);
				}
			}
			for(register int j=1;j<=m;j++){
				suml[j]+=(num[down][j]==0);
				sum[j]=sum[j-1]+down-up-suml[j];
			}
		}
	}
	printf("%d\n",ans);
	return ;
}
int main(){
	for(scanf("%d",&T);T;T--){
		Init();
		Solve();
	}
	return 0;
}