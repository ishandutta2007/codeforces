#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<pair<int,int> >LR[1<<17][30];
int ans[30];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int L,R;cin>>L>>R;
		R++;
		int d=R-L;
		for(int k=0;k<30;k++)
		{
			if(1<<k<=d)
			{
				LR[i][k].push_back(make_pair(0,1<<k));
			}
			else
			{
				int l=L&((1<<k)-1);
				if(l+d<=1<<k)LR[i][k].push_back(make_pair(l,l+d));
				else
				{
					LR[i][k].push_back(make_pair(0,d-((1<<k)-l)));
					LR[i][k].push_back(make_pair(l,1<<k));
				}
			}
		}
	}
	vector<pair<int,bool> >vs;
	vs.reserve(4*N);
	for(int k=0;k<30;k++)
	{
		vs.clear();
		for(int i=0;i<N;i++)for(pair<int,int>p:LR[i][k])
		{
			vs.push_back(make_pair(p.first,true));
			vs.push_back(make_pair(p.second,false));
		}
		sort(vs.begin(),vs.end());
		int cnt=0;
		for(pair<int,bool>p:vs)
		{
			if(p.second)cnt++;
			else cnt--;
			ans[k]=max(ans[k],cnt);
		}
	}
	int Q;cin>>Q;
	for(;Q--;)
	{
		int W;cin>>W;
		int k=0;
		while(!(W>>k&1))k++;
		cout<<ans[k]<<"\n";
	}
}