#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2333333,MOD=23333333333333333;
int n,m,ans,pw[N],hs[N];
unordered_map<int,int>cnt;
void add(int x,int y){
	hs[x]=(hs[x]+pw[y])%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<N;i++)
		pw[i]=i?pw[i-1]*11%MOD:1;
	for(int x,y;m--;)
		cin>>x>>y,add(x,y),add(y,x);
	for(int i=1;i<=n;i++)
		ans+=cnt[hs[i]]++,add(i,i),ans+=cnt[hs[i]]++;
	cout<<ans<<"\n";
}