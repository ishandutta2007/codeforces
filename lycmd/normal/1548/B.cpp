#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010,B=20;
int t,n,a[N],g[B][N],lg[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int ask(int l,int r){
	int k=lg[r-l+1];
	return gcd(g[k][l],g[k][r-(1<<k)+1]);
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=2;i<N;i++)
		lg[i]=lg[i>>1]+1;
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i],g[0][i]=abs(a[i]-a[i-1]);
		for(int i=1;i<B;i++)
			for(int j=2;j<=n-(1<<(i-1));j++)
				g[i][j]=gcd(g[i-1][j],g[i-1][j+(1<<(i-1))]);
		int ans=0;
		for(int i=1,p=2;i<=n;p=max(p,(++i)+1)){
			while(p<=n&&ask(i+1,p)!=1)p++;
			ans=max(ans,p-i);
		}
		cout<<ans<<"\n";
	}
}