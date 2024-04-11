#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int a[311111];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	ll sum=0;
	sort(a,a+n);reverse(a,a+n);
	for(int i=0;i<n;i++)sum+=a[i];
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		cout<<sum-a[x-1]<<endl;
	}
	return 0;
}