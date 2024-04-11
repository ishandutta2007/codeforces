#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define sp ' '
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
const int N=2e5+5;
const double pi=acos(-1);
vector<int>	v[N],pos[N];
int n,up[N],a[N];
int f(int x)	{
	return	up[x]==x?up[x]:up[x]=f(up[x]);
}
void uni(int u,int v)	{ up[f(u)]=f(v);}
signed main()	{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		up[i]=i;
	}
	for(int i=1;i<n;++i){
		char c;	
		cin>>c;
		if(c=='1')uni(i,i+1);
	}
	for(int i=1;i<=n;++i){
		v[f(i)].pb(a[i]);
		pos[f(i)].pb(i);
	}
	for(int i=1;i<=n;++i){
		if(i!=f(i))continue;
		sort(v[i].begin(),v[i].end());
		for(int j=0;j<pos[i].size();++j)
			a[pos[i][j]]=v[i][j];
	}
	for(int i=1;i<=n;++i)	
		if(a[i]!=i)	
		{cout<<"NO";return 0;}
	cout<<"YES";
}