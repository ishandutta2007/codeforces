#include<bits/stdc++.h>
using namespace std;
int const N=500010,MOD=1000003;
int n,m,ans=1,a[N][2],b[N][2];
char c;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c,c>47&&(a[i][(j&1)^(c<51)]=b[j][(i&1)^!(c&2)]=1);
	for(int i=1;i<=n;i++)
		ans=ans*(2-a[i][0]-a[i][1])%MOD;
	for(int i=1;i<=m;i++)
		ans=ans*(2-b[i][0]-b[i][1])%MOD;
	cout<<ans<<"\n"; 
}