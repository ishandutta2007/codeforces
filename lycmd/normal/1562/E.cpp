#include<bits/stdc++.h>
using namespace std;
int const N=5010;
int t,n,g[N][N],f[N];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s,s=" "+s;
		for(int i=n;i>=1;i--)
			for(int j=i-1;j>=1;j--)
				g[i][j]=s[i]^s[j]?0:(i>n?0:g[i+1][j+1])+1;
		f[1]=n;
		for(int i=2;i<=n;i++){
			f[i]=n-i+1;
			for(int j=1;j<i;j++){
				int p=g[i][j];
				f[i]=max(f[i],(i+p<=n+1&&s[i+p]>s[j+p])*(f[j]+n-i+1-p));
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,f[i]);
		cout<<ans<<"\n";
	}
}