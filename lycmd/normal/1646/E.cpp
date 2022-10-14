#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=31,M=1000010,T=10000010;
int n,m,ans[N];
bitset<N*M>cnt,vis;
signed main(){
	cin>>n>>m;
	for(int i=1;i<N;i++){
		ans[i]=ans[i-1];
		for(int j=1;j<=m;j++)
			ans[i]+=!cnt[i*j],cnt[i*j]=1;
	}
	int tot=n-1,res=1;
	for(int i=2;i*i<=n;i++)
		if(!vis[i]){
			int c=1,t=i;
			while(t<=n)vis[t]=1,t*=i,c++;
			c--,res+=ans[c],tot-=c;
		}
	res+=ans[1]*tot;
	cout<<res<<"\n";
}