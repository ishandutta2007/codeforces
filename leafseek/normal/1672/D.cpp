#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5;
int a[MaxN],b[MaxN];
bool ok[MaxN];
vector<int> lit[MaxN];
int lit_Tot[MaxN],lit_Cur[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n;
		rep(i,1,n) cin>>a[i];
		rep(i,1,n) cin>>b[i],ok[i]=true;
		rep(i,1,n) lit_Tot[i]=lit_Cur[i]=0;
		rep(i,1,n-1) if(b[i]==b[i+1]) ++lit_Tot[b[i]],lit[b[i]].push_back(i);
		int p=1;
		bool Flag=true;
		rep(i,1,n)
		{
			if(a[i]==b[p])
			{
				if(p!=n&&b[p]==b[p+1])
					++lit_Cur[b[p]];
				++p;
				if(p<=n) while(!ok[p]) ++p;
				continue;
			}
			if(lit_Cur[a[i]]==lit_Tot[a[i]])
				{Flag=false;break;}
			ok[lit[a[i]][lit_Cur[a[i]]++]]=false;
		}
		rep(i,1,n) lit[i].clear();
		if(Flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}