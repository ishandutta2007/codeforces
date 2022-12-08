#include <bits/stdc++.h>

using namespace std;

int p[1000006];

void dora()
{
	for(int i=2; i<=1000000; i++)
	{
		if(!p[i])
		{
			for(int j=i; j<=1000000; j+=i)
			{
				p[j]=i;
			}
		}
	}
}

int cnt[1000006];
int cnt1[1000006];
int mxx[1000006];

signed main()
{
	ios::sync_with_stdio(false);
	dora();
	int n, k;
	cin>>n>>k;
	while(k>1)
	{
		cnt[p[k]]++;
		k/=p[k];
	}
	for(int i=1; i<=n; i++)
	{
		cin>>k;
		cnt[0]=k;
		while(k>1)
		{
			cnt1[p[k]]++;
			mxx[p[k]]=max(mxx[p[k]], cnt1[p[k]]);
			k/=p[k];
		}
		while(cnt[0]>1)
		{
			cnt1[p[cnt[0]]]--;
			cnt[0]/=p[cnt[0]];
		}
	}
	for(int i=2; i<=1000000; i++)
	{
		if(cnt[i]>mxx[i])
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
}