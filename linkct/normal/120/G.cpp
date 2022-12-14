#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
#define inf 1e9
#define eps 1e-10
#define md
#define N 510
using namespace std;
int A[N][2],B[N][2],C[N],D[N][N];
char st[N][50];
queue<int> q;
vector<int> vec[N];
int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,T;
	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d%d",&A[i][0],&B[i][0],&A[i][1],&B[i][1]);
	int m;
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%s%d",st[i],&C[i]);
		q.push(i);
	}
	int now=-1;
	while (!q.empty())
	{
		now=(now+1)%(2*n);
		int j=now/n,i=(now%n)+1,r=j^1;
		int t=T;
		while (t>0&&(!q.empty()))
		{
			int k=q.front(); q.pop();
			int need=max(1,C[k]-(A[i][j]+B[i][r])-D[i][k]);
			if (t>=need) vec[i].push_back(k);
			  else { q.push(k); D[i][k]+=t; }
			t-=need;
		}
	}
	for (int i=1;i<=n;i++)
	{
		int po=vec[i].size();
		printf("%d",po);
		for (int j=0;j<po;j++) printf(" %s",st[vec[i][j]]);
		printf("\n");
	}
	return 0;
}