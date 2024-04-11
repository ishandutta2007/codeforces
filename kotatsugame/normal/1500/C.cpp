#include<cstdio>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
int N,M;
int id[1500];
bool vis[1500];
using bit=bitset<1499>;
bit GT[1500];
int inv[1500],idx[1500];
pair<int,int>K[1500];
int cnt[1500];
int rd()
{
	char c=getchar();
	int ret=0;
	while('0'<=c&&c<='9')
	{
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
main()
{
	N=rd();
	M=rd();
	vector<vector<int> >A(N),B(N);
	for(int i=0;i<N;i++)
	{
		A[i].assign(M,0);
		for(int j=0;j<M;j++)
		{
			A[i][j]=rd();
		}
	}
	for(int i=0;i<N;i++)
	{
		B[i].assign(M,0);
		for(int j=0;j<M;j++)
		{
			B[i][j]=rd();
		}
	}
	vector<int>can;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N-1;j++)
		{
			if(B[j][i]>B[j+1][i])
			{
				GT[i][j]=1;
				cnt[i]++;
			}
		}
		if(!cnt[i])can.push_back(i);
	}
	vector<int>ans;
	bit mk;
	for(int j=0;j<N-1;j++)mk[j]=1;
	while(true)
	{
		int id=-1;
		for(int i:can)if(!vis[i])
		{
			id=i;
			break;
		}
		if(id==-1)break;
		vis[id]=true;
		bool ch=false;
		for(int j=0;j<N-1;j++)if(mk[j]==1)
		{
			if(B[j][id]<B[j+1][id])
			{
				mk[j]=0;
				for(int i=0;i<M;i++)if(GT[i][j]==1)
				{
					cnt[i]--;
					if(!cnt[i])can.push_back(i);
				}
				ch=true;
			}
		}
		if(ch)ans.push_back(id);
	}
	for(int i=ans.size();i--;)
	{
		int id=ans[i];
		for(int j=0;j<N;j++)K[j]=make_pair(A[j][id],j);
		sort(K,K+N);
		for(int j=0;j<N;j++)inv[j]=idx[j]=j;
		for(int j=0;j<N-1;j++)
		{
			if(inv[K[j].second]!=j)
			{
				A[j].swap(A[inv[K[j].second]]);
				int tmp=idx[j];
				idx[j]=K[j].second;
				idx[inv[K[j].second]]=tmp;
				inv[tmp]=inv[K[j].second];
				inv[K[j].second]=j;
			}
		}
	}
	if(A!=B)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",ans.size());
	for(int i=ans.size();i--;)printf("%d%c",ans[i]+1,i==0?10:32);
}