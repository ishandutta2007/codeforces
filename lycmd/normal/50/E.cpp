#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=20000010,M=N/2;
int n,m,ans,a[N];
void add(int l,int r){
	a[l+M]++,a[r+1+M]--;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ans+=min(i*i,m)*2;
		int l=ceil(sqrtl(max(0ll,i*i-m))),r=sqrtl(i*i-1);
		add(l-i,r-i),add(-r-i,-l-i);
	}
	for(int i=1;i<N;i++)
		ans-=max(0ll,(a[i]+=a[i-1])-1);
	cout<<ans<<"\n";
}