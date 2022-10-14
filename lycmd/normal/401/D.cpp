#include<bits/stdc++.h>
using namespace std;
int const N=270010,M=105,T=12;
int n,m,vis[T];
long long f[N][M];
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin>>s>>m,n=s.size(),f[0][0]=1;
	for(int i=0;i<1<<n;i++){
		memset(vis,0,sizeof vis);
		for(int j=0;j<n;j++){
			int t=s[j]^48;
			if((i>>j&1)&&(t||(i^(1ll<<j)))&&!vis[t]){
				for(int k=0;k<m;k++)
					f[i][(k*10+t)%m]+=f[i^(1ll<<j)][k];
				vis[t]=1;
			}
		}
	}
	cout<<f[(1<<n)-1][0]<<"\n";
}