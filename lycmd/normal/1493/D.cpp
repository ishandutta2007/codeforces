#include<bits/stdc++.h>
using namespace std;
int const N=233333,MOD=1000000007;
int n,q,ans=1,pre[N];
map<int,int>a[N],cnt[N];
void ins(int p,int x){
	for(;x>1;x/=pre[x]){
		int t=pre[x];
		ans=1ll*ans*(++cnt[t][++a[p][t]]==n?t:1)%MOD;
	}
}
int main(){
	ios::sync_with_stdio(0);
	for(int i=2;i<N;i++)
		if(!pre[i])
			for(int j=i;j<N;j+=i)
				pre[j]=i;
	cin>>n>>q;
	for(int i=1,a;i<=n;i++)
		cin>>a,ins(i,a);
	for(int x,y;q--;)
		cin>>x>>y,ins(x,y),cout<<ans<<"\n";
	return 0; 
}