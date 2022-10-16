#include<bits/stdc++.h>
#define int long long
const int N=105;
using namespace std;

int n,a[N],b[N];
int f[N][2*N*N],s[N];

void solve(){
	cin>>n;
	int res=0,sm=0;
	for(int i=1;i<=n;i++)cin>>a[i],res+=a[i]*a[i];
	for(int i=1;i<=n;i++)cin>>b[i],res+=b[i]*b[i];
	res*=n-1;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i]+b[i];
	memset(f,1,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sm;j++){
			f[i][j+a[i]]=min(f[i][j+a[i]],f[i-1][j]+a[i]*j+b[i]*(s[i-1]-j));
			f[i][j+b[i]]=min(f[i][j+b[i]],f[i-1][j]+b[i]*j+a[i]*(s[i-1]-j));
		}
		sm+=a[i]+b[i];
	}
	int mn=1e18;
	for(int i=0;i<=sm;i++)
		mn=min(mn,f[n][i]);
	cout<<2*mn+res<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}