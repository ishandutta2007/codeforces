#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=10000010;
int n,tot=1,ans,a,x,cnt[N],tr[N][2],f[33][2];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>n;n--;){
		cin>>a;
		int p=1;cnt[p]++;
		for(int i=30;~i;i--){
			int t=a>>i&1,&y=tr[p][t];
			f[i][t]+=cnt[tr[p][!t]];
			cnt[p=y?y:y=++tot]++;
		}
	}
	for(int i=30;~i;i--)
		ans+=min(f[i][0],f[i][1]),x|=(f[i][0]>f[i][1])<<i;
	cout<<ans<<" "<<x<<"\n";
}