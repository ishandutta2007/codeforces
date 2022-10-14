#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,MOD=1000000007;
int n,ans,a[N],cnt[N];
vector<int>p[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=1;i<N;i++)
		for(int j=i;j<N;j+=i)
			p[j].push_back(i-1);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt[a[i]]++;
	for(int i=1;i<N;i++)
		cnt[i]+=cnt[i-1];
	for(int i=1;cnt[i-1]<n;i++){
		int t=1,c=p[i].size();
		for(int j=1;j<c;j++)
			t=t*qpow(j,cnt[p[i][j]]-cnt[p[i][j-1]])%MOD;
		ans=(ans+t*(qpow(c,n-cnt[p[i][c-1]])-qpow(c-1,n-cnt[p[i][c-1]])+MOD)%MOD)%MOD;
	}
	cout<<ans<<"\n";
}