#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	string ty;
	vector<vector<int>> visC(25,vector<int>(360));
	vector<vector<int>> visS(25,vector<int>(360));
	int r1,r2,t1,t2;
	for(int tt=1;tt<=n;tt++)
	{
		cin>>ty;
		if(ty[0]=='C')
		{
			cin>>r1>>t1>>t2;
			for(int i=t1;i!=t2;i=(i+1)%360)
			{
				visC[r1-1][i]=1;
			}
		}
		else
		{
			cin>>r1>>r2>>t1;
			for(int i=r1;i!=r2;i++)
			{
				visS[i][(t1+359)%360]=1;
			}
		}
	}
	auto hs=[](int x,int y)
	{
		return x*360+y+1;
	};
	vector<int> pa(25*360);
	function<int(int)> find=[&](int x)
	{
		return pa[x]?pa[x]=find(pa[x]):x;
	};
	for(int i=0;i<=20;i++)
	{
		for(int j=0;j<360;j++)
		{
			if(not visC[i][j])
			{
				int pu=find(hs(i,j)),pv=find(hs(i+1,j));
				if(pu!=pv)
				{
					pa[pu]=pv;
				}
			}
			if(not visS[i][j])
			{
				int pu=find(hs(i,j)),pv=find(hs(i,(j+1)%360));
				if(pu!=pv)
				{
					pa[pu]=pv;
				}
			}
		}
	}
	if(find(hs(0,0))==find(hs(21,0)))
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
	
	return 0;
}