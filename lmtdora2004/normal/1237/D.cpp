#include <bits/stdc++.h>
#define int long long
#define in jidajs
using namespace std;

int ax[200005][20], in[200005][20];
int deohieu[100005];
int lol[100005];
int a[200005];
deque<int> g, g1;
int n;

int gmax(int l, int r)
{
	int aa=log2(r-l+1), bb=(1<<aa);
	return max(ax[l][aa], ax[r-bb+1][aa]);
}

int gmin(int l, int r)
{
	int aa=log2(r-l+1), bb=(1<<aa);
	return min(in[l][aa], in[r-bb+1][aa]);
}

signed main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		a[n+i]=a[i];
	}
	for(int i=1; i<=2*n; i++)
	{
		ax[i][0]=a[i];
		in[i][0]=a[i];
	}
	for(int i=1; i<=20; i++)
	{
		for(int j=1; j<=2*n-(1<<i)+1; j++)
		{
			ax[j][i]=max(ax[j][i-1], ax[j+(1<<(i-1))][i-1]);
			in[j][i]=min(in[j][i-1], in[j+(1<<(i-1))][i-1]);
		}
	}
	// cout<<gmax(1, n)<<" "<<gmin(1, n)<<endl;
	if(gmax(1, n)<=gmin(1,n)*2)
	{
		for(int i=1; i<=n; i++)
		{
			cout<<-1<<" ";
		}
		return 0;
	}
	for(int i=1; i<=n; i++)
	{
		int lo=i+1, hi=i+n;
		// cout<<i<<" "<<gmin(i+1, i+n);
		if(gmin(i+1, i+n)*2>=a[i]) lol[i]=1000000000;
		else
		{
			while(lo<hi)
			{
				int mid=(lo+hi)/2;
				if(gmin(i+1, mid)*2<a[i])
				{
					hi=mid;
				}
				else
				{
					lo=mid+1;
				}
			}
			lol[i]=lo;
		}
	}
	for(int i=1; i<=n; i++)
	{
		g.push_back(lol[i]);
		while(g1.size()&&g1.back()>lol[i])
		{
			g1.pop_back();
		}
		g1.push_back(lol[i]);
	}
	// for(int i=1; i<=n; i++)
	// {
	// 	cout<<lol[i]<<endl;
	// }
	for(int i=1; i<=n; i++)
	{
		cout<<g1.front()-i<<" ";
		if(g.front()==g1.front())
		{
			g1.pop_front();
		}
		g.pop_front();
		g.push_back(lol[i]+n);
		while(g1.size()&&g1.back()>lol[i]+n)
		{
			g1.pop_back();
		}
		g1.push_back(lol[i]+n);
	}
}