#include<iostream>
using namespace std;
int T,N;
string S;
long long ans;
void solve(int id,int H,int W,int D,int R)
{
	if(id==S.size())
	{
		ans+=(long long)H*W;
		return;
	}
	char op=S[id];
	int cnt=0;
	while(id<S.size()&&S[id]==op)id++,cnt++;
	ans+=(long long)cnt*(W-R);
	solve(id,W,H-cnt,R,D-cnt);
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		if(S[0]=='D')
		{
			for(char&c:S)
			{
				c=c=='D'?'R':'D';
			}
		}
		int D=0,R=0;
		for(char c:S)
		{
			if(c=='D')D++;
			else R++;
		}
		int id=0;
		while(id<S.size()&&S[id]=='R')id++;
		if(id<S.size())
		{
			ans=id;
			solve(id,N,N-id,D,R-id);
		}
		else
		{
			ans=N;
		}
		cout<<ans<<"\n";
	}
}