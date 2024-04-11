#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,sum;
vector<vector<int> >a;
vector<int>vr,vc;
map<int,int>s,c;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		a[i].resize(m+1);
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=i*c[a[i][j]]-s[a[i][j]],s[a[i][j]]+=i,c[a[i][j]]++;
	s.clear(),c.clear();
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			ans+=j*c[a[i][j]]-s[a[i][j]],s[a[i][j]]+=j,c[a[i][j]]++;
	cout<<ans<<"\n";
}