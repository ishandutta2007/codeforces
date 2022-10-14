#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,x,y,ans,cnt[4];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x>>y,cnt[(x&2)|((y&2)>>1)]++;
	for(int i=0;i<4;i++)
		ans+=cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6+cnt[i]*(cnt[i]-1)/2*(n-cnt[i]);
	cout<<ans;
}