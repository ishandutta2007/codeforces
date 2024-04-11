#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
bitset<7007> b[111111],di[11111],mu[11111],ans;
int n,q,tp,x,y,z,miu[11111],prime[11111],cnt;
const int maxn=7000;
bool f[11111]; 
int main()
{
	miu[1]=1;
	for (int i=2;i<=maxn;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
			miu[i]=-1;
		}
		for (int j=1;j<=cnt && i*prime[j]<=maxn;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0)
			{
				miu[i*prime[j]]=0;
				break;
			}
			miu[i*prime[j]]=-miu[i];
		}
	}
	for (int i=1;i<=maxn;i++)
	{
		for (int j=i;j<=maxn;j+=i)
		{
			di[j][i]=1;
			if (miu[j/i]) mu[i][j]=1;
		}
	}
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%d%d",&x,&y);
			b[x]=di[y];
		}
		else if (tp==2)
		{
			scanf("%d%d%d",&x,&y,&z);
			b[x]=b[y]^b[z];
		}
		else if (tp==3)
		{
			scanf("%d%d%d",&x,&y,&z);
			b[x]=b[y]&b[z];
		}
		else
		{
			scanf("%d%d",&x,&y);
			ans=b[x]&mu[y];
			printf("%d",ans.count()&1);
		}
	}
	return Accepted;
}