#include<bits/stdc++.h>
#define int long long
#define gb(x) (__builtin_ctz(x)+1)
using namespace std;
int const N=23,M=1000010;
int n,m,ans,f[M][N];
vector<int>e[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		f[1<<(i-1)][i]=1;
	for(int i=1;i<1<<n;i++)
		for(int x=1;x<=n;x++)
			if(f[i][x])
				for(int y:e[x])
					if((i&-i)<=(1<<(y-1))){
						if(i>>(y-1)&1){
							if((i&-i)==(1<<y-1))
								ans+=f[i][x];
						}else f[i|1<<(y-1)][y]+=f[i][x];
					}
	cout<<(ans-m)/2<<"\n";
}