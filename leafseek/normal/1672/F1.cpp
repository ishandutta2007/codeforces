#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=200000+5;
int arr[MaxN],cnt[MaxN],Eta[MaxN];
queue<int> que[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n;
		rep(i,1,n) cin>>arr[i],++cnt[arr[i]];
		rep(i,1,n) que[cnt[i]].push(i),Eta[i]=0;
		int u,v=0,S;
		dow(i,n,1)
			while(!que[i].empty())
				u=que[i].front(),que[i].pop(),(v?(Eta[v]=u):(S=u)),v=u;
		rep(i,1,n)
			u=arr[i],v=Eta[u],cout<<(cnt[v]?((--cnt[v]),v):((--cnt[S]),S))<<' ';
		cout<<'\n';
	}
	return 0;
}