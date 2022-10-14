#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=500010,MOD=1000000007;
int n,ans,a[N],b[N],p[N],tr[N];
void add(int x,int y){
	for(;x<=n;x+=x&-x)tr[x]+=y;
}
int ask(int x){
	int res=0;
	for(;x;x&=x-1)res+=tr[x];
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i],ans=(ans+a[i]*i%MOD*(n-i+1)%MOD)%MOD;
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
		p[i]=lower_bound(b+1,b+1+n,a[i])-b;
	for(int i=1;i<=n;i++)
		ans=(ans+ask(p[i])*(n-i+1)%MOD*a[i]%MOD)%MOD,add(p[i],i);
	memset(tr,0,sizeof tr);
	for(int i=n;i>=1;i--)
		ans=(ans+ask(p[i])*i%MOD*a[i]%MOD)%MOD,add(p[i],n-i+1);
	cout<<ans<<"\n"; 
}