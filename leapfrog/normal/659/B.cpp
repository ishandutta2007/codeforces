//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
typedef pair<int,string>pi;int n,m;vector<pi>v[1000005];
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++)
	{
		string s;cin>>s;int x,y;read(x),read(y);
		v[x].push_back(make_pair(y,s));
	}for(int i=1;i<=m;i++) sort(v[i].begin(),v[i].end(),greater<pi>());
	for(int i=1;i<=m;i++)
	{
		if((int)v[i].size()>2&&v[i][1].first==v[i][2].first) cout<<"?"<<endl;
		else cout<<v[i][0].second<<" "<<v[i][1].second<<endl;
	}
	return 0;
}