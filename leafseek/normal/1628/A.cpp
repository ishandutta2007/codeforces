#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=400000+5;
vector<int> t[MaxN];
int a[MaxN],b[MaxN],c[MaxN];
bitset<MaxN> Bit;
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T,N=300000;
	cin>>T;
	rep(i,0,N)
		t[i].push_back(0);
	int n;
	rep(TTT,1,T)
	{
		cin>>n,c[0]=0;
		rep(i,1,n)
		{
			cin>>a[i];
			t[a[i]].push_back(i);
		}
		rep(i,0,n)
			t[i].push_back(1<<29);
		int I=0;
		rep(i,0,n) Bit[i]=false;
		dow(i,n,1)
		{
			Bit[a[i]]=true;
			while(Bit[I]) ++I;
			b[i]=I;
		}
		rep(i,0,n) t[i][0]=1;
		int P=1;
		while(P!=(n+1))
		{
			int Mex=b[P],Max=P;
			rep(i,0,Mex-1)
				Max=max(Max,t[i][t[i][0]]);
			P=(Max+1);
			rep(i,0,Mex-1)
			{
				while(t[i][t[i][0]]<P) ++t[i][0];
			}
			c[++c[0]]=Mex;
		}
		rep(i,0,n)
			t[i].clear(),t[i].push_back(0);
		cout<<c[0]<<'\n';
		rep(i,1,c[0])
			cout<<c[i]<<' ';
		cout<<'\n';
	}
	return 0;
}