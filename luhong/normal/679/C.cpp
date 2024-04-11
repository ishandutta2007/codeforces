#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool mp[510][510];char s[510];
int ltk[250010],bj[510][510],sum[510][510];
bool used[510][510];int use[250010];int n,k;
int q[250010],cnt=0,ans=-1;
void ins(int x,int &sum){if(++use[x]==1)sum+=ltk[x];}
void del(int x,int &sum){if(--use[x]==0)sum-=ltk[x];}
void dfs(int x,int y,int i,int j,int z)
{
	if(mp[i][j]!=1||used[i][j]||i>n||j>n||i<0||j<0)return;
	used[i][j]=1;dfs(x,y,i+1,j,z);dfs(x,y,i,j+1,z);dfs(x,y,i-1,j,z);dfs(x,y,i,j-1,z);
	bj[i][j]=z;ltk[z]++;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<n;j++)mp[i][j+1]=s[j]=='.'?1:0;
	}
	int tot=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mp[i][j];
		if(!used[i][j]&&mp[i][j]==1)dfs(i,j,i,j,++tot);
	}
	memset(used,0,sizeof(used));
//	for(int i=1;i<=n;i++,cout<<endl);
//	for(int j=1;j<=n;j++)cout<<bj[i][j]<<' ';
	for(int i=1,s2=0;i+k-1<=n;i++,s2=0)
	for(int j=1;j+k-1<=n;j++)
	{
		int s=0;cnt=0;
		if(j==1)
		{
			memset(use,0,sizeof(use));
			for(int r=i;r<=i+k-1;r++)
			for(int c=1;c<=k;c++)ins(bj[r][c],s2);
			ans=max(ans,s+s2+k*k-(sum[i+k-1][j+k-1]-sum[i-1][j+k-1]-sum[i+k-1][j-1]+sum[i-1][j-1]));
			
		}
		else
		for(int l=i;l<=i+k-1;l++)
		{
			del(bj[l][j-1],s2);ins(bj[l][j+k-1],s2);
//			cout<<i<<' '<<j<<" "<<l<<" "<<j-1<<" "<<l<<" "<<j+k-1<<endl;
		}
		for(int l=j;l<=j+k-1;l++)
		{
			ins(bj[i-1][l],s);ins(bj[i+k][l],s);q[++cnt]=bj[i-1][l];q[++cnt]=bj[i+k][l];
//			cout<<i<<' '<<j<<" "<<i-1<<" "<<l<<" "<<i+k<<" "<<l<<endl;
		}
		for(int l=i;l<=i+k-1;l++)
		{
			ins(bj[l][j-1],s);ins(bj[l][j+k],s);q[++cnt]=bj[l][j-1];q[++cnt]=bj[l][j+k];
//			cout<<i<<' '<<j<<" "<<l<<" "<<j-1<<" "<<l<<" "<<j+k<<endl;
		}
		for(int l=1;l<=cnt;l++)use[q[l]]--;
//		cout<<s+k*k-(sum[i+k-1][j+k-1]-sum[i-1][j+k-1]-sum[i+k-1][j-1]+sum[i-1][j-1])<<endl;
		ans=max(ans,s+s2+k*k-(sum[i+k-1][j+k-1]-sum[i-1][j+k-1]-sum[i+k-1][j-1]+sum[i-1][j-1]));
//		if(s+s2+k*k-(sum[i+k-1][j+k-1]-sum[i-1][j+k-1]-sum[i+k-1][j-1]+sum[i-1][j-1])==ans)cout<<i<<" "<<j<<" "<<ans<<endl; 
	}
	printf("%d",ans);
	return 0;
 }