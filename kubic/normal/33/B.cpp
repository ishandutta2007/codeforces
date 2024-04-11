#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 35
#define INF 0x3f3f3f3f
#define min(x,y) ((x)<(y)?(x):(y))
#define set(a,v) memset(a,v,sizeof(a))
int n,lA[2],ans1,dp[M][M];char a[2][N],ans2[N];
int main()
{
	for(int i=0;i<2;++i) scanf("%s",a[i]+1),lA[i]=strlen(a[i]+1);
	if(lA[0]!=lA[1]) {puts("-1");return 0;}scanf("%d",&n);set(dp,INF);for(int i=0;i<26;++i) dp[i][i]=0;
	for(int i=1,w;i<=n;++i) {char u[2],v[2];scanf("%s %s %d",u,v,&w);dp[u[0]-'a'][v[0]-'a']=min(dp[u[0]-'a'][v[0]-'a'],w);}
	for(int k=0;k<26;++k) for(int i=0;i<26;++i) for(int j=0;j<26;++j) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int i=1,t1,t2;i<=lA[0];++i)
	{
		if(a[0][i]==a[1][i]) {ans2[i]=a[0][i];continue;}
		t1=INF;for(int j=0;j<26;++j) if(dp[a[0][i]-'a'][j]+dp[a[1][i]-'a'][j]<t1) t1=dp[a[0][i]-'a'][j]+dp[a[1][i]-'a'][j],t2=j;
		if(t1==INF) {puts("-1");return 0;}ans1+=t1;ans2[i]=t2+'a';
	}
	printf("%d\n",ans1);for(int i=1;i<=lA[0];++i) printf("%c",ans2[i]);puts("");
}