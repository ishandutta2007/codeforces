#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
pair<int, int> a[200005];
int now=0;
multiset<int> ax;

signed main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i].first;
	}
	for(int i=1; i<=n; i++)
	{
		cin>>a[i].second;
	}
	sort(a+1, a+n+1);
	int lmao=0, sum=0;
	int last=0;
	a[n+1].first=1000000000000;
	for(int i=1; i<=n+1; i++)
	{
		while(last<a[i].first)
		{
			if(ax.size())
			{
				//cout<<i<<" "<<ax.size()<<" "<<last<<" "<<sum<<endl;
				last++;
				//cout<<*ax.begin()<<endl;
				sum-=*ax.begin();
				ax.erase(ax.begin());
				lmao+=sum;
			}
			else
			{
				last=a[i].first;
			}
		}
		ax.insert(-a[i].second);
		sum+=-a[i].second;
	}
	cout<<-lmao;
}