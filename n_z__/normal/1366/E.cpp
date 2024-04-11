#include<bits/stdc++.h>
using namespace std;
#define int long long
multiset<int>s;
int a[200001],b[200001];
main(){
    int n,m;
    cin>>n>>m;
	for(int x=1;x<=n;x++)cin>>a[x];
	for(int x=1;x<=m;x++)cin>>b[x];
	s.insert(a[n]);
	for(int x=n-1;x>=1;x--)
	a[x]=min(a[x],a[x+1]),s.insert(a[x]);
	if(a[1]!=b[1])return puts("0"),0;
	int ans=1;
	for(int x=2;x<=m;x++)
	ans=(ans*s.count(b[x]))%998244353;
	cout<<ans;
}