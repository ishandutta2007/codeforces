#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2010,MOD=1000000007;
int n,h,ans=1,a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>h;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]=h-a[i];
	for(int i=0;i<=n;i++){
		switch(a[i+1]-a[i]){
			case-1:
				ans=ans*a[i]%MOD;break;
			case 0:
				ans=ans*(a[i]+1)%MOD;break;
			case 1:
				break;
			default:
				cout<<"0\n",exit(0);
		}
	}
	cout<<ans<<"\n";
}