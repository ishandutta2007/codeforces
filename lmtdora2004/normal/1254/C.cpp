#include <bits/stdc++.h>
#define up pizdec
#define dn doradangyeu
using namespace std;

int res1;
long long res2;
vector<pair<long long, int> > up, dn;
vector<pair<long long, int> > lu, ru, ld, rd;
signed main()
{
	int n;
	cin>>n;
	pair<long long, int> mu={0, 0}, md={0, 0};
	for(int i=3; i<=n; i++)
	{
		cout<<"2 1 2 "<<i<<endl;
		cin>>res1;
		cout<<"1 1 2 "<<i<<endl;
		cin>>res2;
		if(res1==1)
		{
			up.push_back({res2, i});	
			mu=max(mu, {res2, i});
		}
		else
		{
			dn.push_back({res2, i});
			md=max(md, {res2, i});
		}
	}
	if(up.size())
	{
		for(auto i:up)
		{
			if(i!=mu)
			{
				cout<<"2 1 "<<mu.second<<" "<<i.second<<endl;
				cin>>res1;
				if(res1==1)
				{
					lu.push_back(i);
				}
				else
				{
					ru.push_back(i);
				}
			}
		}
	}
	if(dn.size())
	{
		for(auto i:dn)
		{
			if(i!=md)
			{
				cout<<"2 1 "<<md.second<<" "<<i.second<<endl;
				cin>>res1;
				if(res1==1)
				{
					rd.push_back(i);
				}
				else
				{
					ld.push_back(i);
				}
			}
		}
	}
	if(ld.size()) sort(ld.begin(), ld.end());
	if(rd.size()) sort(rd.begin(), rd.end());
	if(lu.size()) sort(lu.begin(), lu.end());
	if(ru.size()) sort(ru.begin(), ru.end());
	cout<<"0 1 ";
	if(dn.size())
	{
		for(int i=0; i<(int)ld.size(); i++)
		{
			cout<<ld[i].second<<" ";
		}
		cout<<md.second<<" ";
		for(int i=(int)rd.size()-1; i>=0; i--)
		{
			cout<<rd[i].second<<" ";
		}
	}
	cout<<"2 ";
	if(up.size())
	{
		for(int i=0; i<(int)ru.size(); i++)
		{
			cout<<ru[i].second<<" ";
		}
		cout<<mu.second<<" ";
		for(int i=(int)lu.size()-1; i>=0; i--)
		{
			cout<<lu[i].second<<" ";
		}
	}
	cout<<endl;
}