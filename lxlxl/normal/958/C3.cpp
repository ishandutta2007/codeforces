#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 510000;
const int maxk = 105;
const int maxp = 105;

int n,K,P;
int a[maxn],sum[maxn];
int nex[maxp][maxn];
int f[maxk][maxk*maxp];

vector<int>V[maxn];

void upd(int &x,int y){ if(x==-1||x>y)x=y; }

int main()
{
	//freopen("tmp.in","r",stdin);
//	freopen("tmp.out","w",stdout);
	
	scanf("%d%d%d",&n,&K,&P);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); a[i]%=P;
		sum[i]=(sum[i-1]+a[i])%P;
	}
	for(int i=1;i<=n;i++) V[sum[i]].push_back(i);
	
	for(int i=0;i<P;i++)
	{
		nex[i][0]=!(int)V[i].size()?-1:0;
		for(int j=1;j<=n;j++)
		{
			int k=nex[i][j-1];
			if(k==-1||(int)V[i][k]>=j) nex[i][j]=k;
			else
			{
				if(k<(int)V[i].size()-1) k++;
				else k=-1;
				nex[i][j]=k;
			}
		}
		//if(nex[i][n]>=(int)V[i].size()) puts("fuck");
	}
	memset(f,-1,sizeof f);
	f[0][0]=0;
	for(int i=1;i<K;i++)
	{
		int uj=(i-1)*(P-1);
		for(int j=0;j<=uj;j++) if(f[i-1][j]!=-1&&f[i-1][j]!=n)
		{
			for(int k=0;k<P;k++) if(nex[k][f[i-1][j]+1]!=-1)
			{
				int tx=nex[k][f[i-1][j]+1],cc=(k-sum[f[i-1][j]]+P)%P;
				upd(f[i][j+cc],V[k][tx]);
			}
		}
	}
	int ans=K*P;
	for(int i=0;i<=(K-1)*(P-1);i++) if(f[K-1][i]!=-1&&f[K-1][i]<n)
		ans=min(ans,i+(sum[n]-sum[f[K-1][i]]+P)%P);
	printf("%d\n",ans);
	
    return 0;
}