#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int> >ans;
void add(int x,int y,int b){ans.push_back(make_pair(x*b,y*b));}
void upd(int from,int to,int b)
{
	while(from!=to)
	{
		add(from,0,b);
		add(from,from,b);
		from*=2;
	}
}
int solve(int N,int b)
{
	if(N==3||N==4)
	{
		add(1,3,b);
		add(2,2,b);
		return 4;
	}
	else if(N==5)
	{
		add(3,5,b);
		add(2,2,b);
		upd(1,8,b);
		upd(4,8,b);
		upd(4,8,b);
		return 8;
	}
	else if(N==6)
	{
		add(2,6,b);
		add(3,5,b);
		add(4,4,b);
		upd(1,8,b);
		upd(2,8,b);
		return 8;
	}
	int t=1;
	while(N>=t*2)t*=2;
	if(N==t)
	{
		return solve(N-1,b);
	}
	int r=N-t;
	for(int i=1;i<=r;i++)
	{
		add(t-i,t+i,b);
	}
	if(t-r-1>=3)
	{
		int n=t-r-1;
		int from=solve(n,b);
		for(int i=2;i<=n;i++)upd(from,t*2,b);
		if(r>=3)
		{
			int from=solve(r,b*2)*2;
			add(0,t*2,b);
			for(int i=2;i<=r;i++)upd(from,t*2,b);
		}
		else
		{
			if(r==2)upd(4,t*2,b);
			upd(2,t*2,b);
		}
		upd(t,t*2,b);
	}
	else if(r>=3)
	{
		int from=solve(r,b*2)*2;
		for(int i=2;i<=r;i++)upd(from,t*2,b);
		if(t-r-1==2)upd(2,t*2,b);
		if(t-r-1>=1)upd(1,t*2,b);
		upd(t,t*2,b);
	}
	else
	{
		cout<<"ERROR"<<endl;
	}
	return t*2;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		if(N==2)cout<<"-1\n";
		else
		{
			ans.clear();
			int ret=solve(N,1);
			add(0,ret,1);
			cout<<ans.size()<<"\n";
			for(pair<int,int>p:ans)cout<<p.first<<" "<<p.second<<"\n";
		}
	}
}