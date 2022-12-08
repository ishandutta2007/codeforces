#include <bits/stdc++.h>
#define next uhidae
#define last jdiodj

using namespace std;

pair<pair<int, int>, pair<int, int> > a[100005];
vector<pair<pair<int, int>, pair<int, int>  > > cac;
vector<int> last;
int n;

void solve()
{
	vector<int> ditme;
	for(int i=0; i<(int)cac.size(); i++)
	{
		if(i!=(int)cac.size()-1&&cac[i].first==cac[i+1].first)
		{
			cout<<cac[i].second.second<<" "<<cac[i+1].second.second<<endl;
			i++;
		}
		else
		{
			ditme.push_back(cac[i].second.second);
		}
	}
	for(int i=0; i<(int)ditme.size(); i++)
	{
		if(i==(int)ditme.size()-1)
		{
			last.push_back(ditme[i]);
			break;
		}
		cout<<ditme[i]<<" "<<ditme[i+1]<<endl;
		i++;
	}
	cac.clear();
	ditme.clear();
}

signed main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i].first.first>>a[i].first.second>>a[i].second.first;
		a[i].second.second=i;
	}
	a[n+1].first={100000001, 0};
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
	{
		int j=i;
		while(a[j].first.first==a[i].first.first)
		{
			cac.push_back(a[j]);
			j++;
		}
		solve();
		i=j-1;
	}
	for(int i=0; i<(int)last.size(); i++)
	{
		cout<<last[i]<<" "<<last[i+1]<<endl;
		i++;
	}
}