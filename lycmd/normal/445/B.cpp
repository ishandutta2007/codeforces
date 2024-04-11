#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,m,ans,f[N];
void init(int n){
	for(int i=1;i<=n;i++)
		f[i]=i;
}
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(f[fx]=fy,1):0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,ans=1ll<<n,init(n);
	while(m--){
		int x,y;cin>>x>>y;
		merge(x,y);
	}
	for(int i=1;i<=n;i++)
		if(f[i]==i)
			ans/=2;
	cout<<ans<<"\n";
}