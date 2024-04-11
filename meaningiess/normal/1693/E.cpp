#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
ll c[N];vector<int> a[N];
void add(int x){for (;x<N;x+=(x&(-x))) c[x]++;}
ll qry(int x){ll res=0;for (;x;x-=(x&(-x))) res+=c[x];return res;}
int main()
{
	int n,i,l,r,t;ll ans=0;cin>>n;l=0;r=n+1;
	for (i=1;i<=n;i++){cin>>t;a[t].push_back(i);}
	for (i=n;i;i--) if (a[i].size())
	{
		int tl=min(r-1,a[i][0]-1),tr=max(l+1,a[i][a[i].size()-1]+1);
		l=tl,r=tr;ans+=qry(r-1)-qry(l);for (auto p:a[i]) add(p);
	}
	cout<<ans+n-a[0].size();
}