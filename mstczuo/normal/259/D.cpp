# include <iostream>
# include <cstdio>
using namespace std;
#define Lk(n) (n==4||n==7)
#define N 12
#define Mod 1000000007;
int m,n,cnt[N],F[N][N][2];
long long ans=0;

void init()
{
	scanf("%d",&m);int a[N]={0};
	for(;m;m/=10)a[++n]=m%10;
	F[0][0][0]=F[0][0][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++){
			F[i][j][0]=F[i-1][j][0]<<3;
			if(j)F[i][j][0]+=F[i-1][j-1][0]<<1;
			for(int k=0;k<a[i];k++)
				F[i][j][1]+=F[i-1][j-Lk(k)][0];
			F[i][j][1]+=F[i-1][j-Lk(a[i])][1];
		}
	for(int i=0;i<=n;i++)cnt[i]=F[n][i][1];cnt[0]--;
}
void DFS(int dep,int left,long long w)
{
	w%=Mod;
	if(dep==0){ ans+=w;ans%=Mod;return; }
	for(int i=0;i<=left;i++)
		if(cnt[i])DFS(dep-1,left-i,w*cnt[i]--),cnt[i]++;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		if(cnt[i])DFS(6,i-1,cnt[i]);
	cout<<ans<<endl;
}