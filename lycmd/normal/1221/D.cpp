#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=300010,INF=0x3f3f3f3f3f3f3f3fll;
int t,n,a[N],b[N],f[N][3];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i];
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				f[i][j]=INF;
		for(int i=0;i<3;i++)
			f[1][i]=i*b[i];
		for(int i=2;i<=n;i++)
			for(int x=0;x<3;x++)
				for(int y=0;y<3;y++)
					if(a[i-1]+x!=a[i]+y)
						f[i][y]=min(f[i][y],f[i-1][x]+y*b[i]);
		int ans=INF;
		for(int i=0;i<3;i++)
			ans=min(ans,f[n][i]);
		cout<<ans<<"\n";
	}
}