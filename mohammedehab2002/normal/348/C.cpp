#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define BU 320
bool ex[100005];
int idx[100005],cnt[BU][100005];
long long arr[100005],sum[100005],upd[100005];
vector<int> v[100005],h;
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
	scanf("%I64d",&arr[i]);
	for (int i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		while (x--)
		{
			int a;
			scanf("%d",&a);
			v[i].push_back(a);
			sum[i]+=arr[a];
		}
		if (v[i].size()>BU)
		{
			idx[i]=h.size();
			h.push_back(i);
		}
	}
	for (int i:h)
	{
		for (int j:v[i])
		ex[j]=1;
		for (int j=0;j<m;j++)
		{
			for (int k:v[j])
			cnt[idx[i]][j]+=ex[k];
		}
		for (int j:v[i])
		ex[j]=0;
	}
	while (q--)
	{
		char c;
		int k,x;
		scanf(" %c%d",&c,&k);
		k--;
		if (c=='?')
		{
			if (v[k].size()<=BU)
			{
				long long ans=0;
				for (int i:v[k])
				ans+=arr[i];
				for (int i:h)
				ans+=cnt[idx[i]][k]*upd[i];
				printf("%I64d\n",ans);
			}
			else
			printf("%I64d\n",sum[k]);
		}
		else
		{
			scanf("%d",&x);
			upd[k]+=x;
			for (int i:h)
			sum[i]+=1LL*cnt[idx[i]][k]*x;
			if (v[k].size()<=BU)
			{
				for (int i:v[k])
				arr[i]+=x;
			}
		}
	}
}