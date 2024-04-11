#include<cstdio>
#include<map>
using namespace std;
int N,M;
long long K,A[20][20];
map<long long,int>mp[20][20];
void dfs(int x,int y,long long C,int rest)
{
	C^=A[x][y];
	if(rest==0)
	{
		mp[x][y][C]++;
		return;
	}
	if(x+1<N)dfs(x+1,y,C,rest-1);
	if(y+1<M)dfs(x,y+1,C,rest-1);
}
long long dfs2(int x,int y,long long C,int rest)
{
	if(rest==0)return mp[x][y].find(C)==mp[x][y].end()?0:mp[x][y][C];
	long long ret=0;
	if(x>0)ret+=dfs2(x-1,y,C^A[x][y],rest-1);
	if(y>0)ret+=dfs2(x,y-1,C^A[x][y],rest-1);
	return ret;
}
main()
{
	scanf("%d%d%lld",&N,&M,&K);
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)scanf("%lld",&A[i][j]);
	int mid=(N+M-2)/2;
	dfs(0,0,K,mid);
	printf("%lld\n",dfs2(N-1,M-1,0,N+M-2-mid));
}