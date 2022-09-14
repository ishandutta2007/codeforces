#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int d[2020];
void ask(int r)
{
	cout<<"? "<<r<<endl;
	for(int i=1;i<=N;i++)cin>>d[i];
}
main()
{
	cin>>N;
	ask(1);
	int mx=0;
	for(int i=1;i<=N;i++)
	{
		mx=max(mx,d[i]);
	}
	vector<vector<int> >vs(mx+1);
	int cnt[2]={};
	vector<pair<int,int> >E;
	for(int i=2;i<=N;i++)
	{
		cnt[d[i]%2]++;
		vs[d[i]].push_back(i);
		if(d[i]==1)E.push_back(minmax(1,i));
	}
	for(int i=cnt[1]<=cnt[0]?1:2;i<=mx;i+=2)
	{
		for(int v:vs[i])
		{
			ask(v);
			for(int j=1;j<=N;j++)
			{
				if(d[j]==1)
				{
					E.push_back(minmax(v,j));
				}
			}
		}
	}
	sort(E.begin(),E.end());
	E.erase(unique(E.begin(),E.end()),E.end());
	cout<<"!"<<endl;
	for(pair<int,int>e:E)cout<<e.first<<" "<<e.second<<endl;
}