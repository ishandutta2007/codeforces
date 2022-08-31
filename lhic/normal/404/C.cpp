#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


vector<pair<int,int>> res;


pair<int,int> d[110000];

int n,k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for (int i=0;i<n;++i)
	{
		cin>>d[i].first;
		d[i].second=i+1;
	}
	sort(d,d+n);
	int now=0;
	int nowcnt=-1;
	if (d[0].first!=0)
	{
		cout<<-1;
		return 0;
	}
	for (int i=1;i<n;++i)
	{
		//cout<<now<<" "<<i<<"\n";
		if (d[i].first==d[now].first)
		{
			cout<<-1;
			return 0;
		}
		if (d[i].first>d[now].first+1)
		{
			while (now<i && d[i].first>d[now].first+1)
				++now;
			nowcnt=0;
		}
		if (d[i].first!=d[now].first+1)
		{
			cout<<-1;
			return 0;
		}
		res.push_back(make_pair(d[now].second,d[i].second));
		++nowcnt;
		if (nowcnt>k-1)
		{
			cout<<-1;
			return 0;
		}
		if (nowcnt==k-1)
		{
			++now;
			nowcnt=0;
		}
		
	}
	cout<<res.size()<<"\n";
	for (int i=0;i<(int)res.size();++i)
	{
		cout<<res[i].first<<" "<<res[i].second<<"\n";
	}
}