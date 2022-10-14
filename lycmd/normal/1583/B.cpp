#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int t,n,m,vis[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=m;i++){
			int a,b,c;cin>>a>>b>>c;
			vis[b]=1;
		}
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				for(int j=1;j<=n;j++)
					if(i!=j)cout<<i<<" "<<j<<"\n";
				break;
			}
	}
}