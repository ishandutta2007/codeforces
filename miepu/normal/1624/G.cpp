#include<bits/stdc++.h>
#define int long long
const int N=1000005,P=31;
using namespace std;

int fa[N];
int gf(int k){return k==fa[k]?k:fa[k]=gf(fa[k]);}

void solve(){
	vector<vector<int>> e;
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		e.push_back({x,y,z,1});
	}
	int ans=0;
	for(int t=P;~t;t--){
		for(int i=1;i<=n;i++)fa[i]=i;
		int cnt=n;
		for(int i=0;i<m;i++){
			if(!e[i][3])continue;
			if(e[i][2]>>t&1)continue;
			int fx=gf(e[i][0]),fy=gf(e[i][1]);
			if(fx!=fy)fa[fx]=fy,cnt--;
		}
		if(cnt==1){
			for(int i=0;i<m;i++)
				if(e[i][2]>>t&1)e[i][3]=0;
		}
		else
			ans|=1<<t;
	}
	cout<<ans<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}