#include<bits/stdc++.h>
using namespace std;
int n,nd,nk;
string s;
map<pair<int,int>,int> M;
inline void solve()
{
	int g,md,mk;
	register int i;
	cin>>n>>s;nd=nk=0;
	M.clear();
	for(i=0;i<n;i++)
	{
		if(s[i]=='D')
			nd++;
		else
			nk++;
		g=__gcd(nd,nk);
		md=nd/g;mk=nk/g;
		cout<<++M[make_pair(md,mk)]<<' ';
	}
	cout<<endl;
	return;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}