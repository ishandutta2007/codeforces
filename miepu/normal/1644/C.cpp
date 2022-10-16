#include<bits/stdc++.h>
#define int long long
const int N=5005;
using namespace std;

int a[N],f[N][N];

void solve(){
	int n,x;cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			f[i][j]=0;
	f[0][0]=0;	
	vector<int> ans(n+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++){
			f[i][j]=max(0ll,f[i-1][j])+a[i];
			if(j)f[i][j]=max(f[i][j],max(0ll,f[i-1][j-1])+a[i]+x);
			ans[j]=max(ans[j],f[i][j]);
		}
	for(int i=0;i<=n;i++)
		cout<<ans[i]<<" ";cout<<endl; 
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}