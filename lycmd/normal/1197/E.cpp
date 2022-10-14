#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> node;
int const N=200010,MOD=1000000007;
int n,f[N],cnt[N];
node a[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n,f[n+1]=MOD;
	for(int i=1;i<=n;i++)
		cin>>a[i].second>>a[i].first;
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		int x=lower_bound(a+1,a+1+n,node{a[i].second,0})-a;
		f[i]=x>n?a[i].first:f[x]-a[i].second+a[i].first;
		cnt[i]=x>n?1:cnt[x];
		if(f[i]>f[i+1])
			f[i]=f[i+1],cnt[i]=cnt[i+1];
		else if(f[i]==f[i+1])
			cnt[i]=(cnt[i]+cnt[i+1])%MOD;
	}
	cout<<cnt[1]<<"\n";
}