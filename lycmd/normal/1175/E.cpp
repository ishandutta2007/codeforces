#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=500010,B=22;
int n,q,f[B][N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	memset(f,-1,sizeof f);
	while(n--){
		int x,y;cin>>x>>y;
		f[0][x]=max(f[0][x],y);
	}
	for(int i=1;i<N;i++)
		f[0][i]=max(f[0][i],f[0][i-1]);
	for(int i=1;i<B;i++)
		for(int j=0;j<N-(1<<(i-1));j++)
			f[i][j]=f[i-1][f[i-1][j]];
	while(q--){
		int l,r,ans=0;cin>>l>>r;
		for(int i=B-1;~i;i--)
			if(~f[i][l]&&f[i][l]<r)
				l=f[i][l],ans|=1<<i;
		cout<<(f[0][l]<r?-1:ans+1)<<"\n";
	}
}