#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=515;
int n,k,a[N],s[N];
set<int>f[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],f[1][i].insert(s[i]=s[i-1]+a[i]);
	for(int i=2;i<=k;i++)
		for(int l=1;l<=n;l++)
			for(int r=l;r<=n;r++)
				for(auto x:f[i-1][l-1])
					f[i][r].insert(x&(s[r]-s[l-1]));
	cout<<*f[k][n].rbegin()<<"\n";
}