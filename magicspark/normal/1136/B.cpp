#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,k;
int main(){
	cin>>n>>k;
	int ans;
	if(k==n)ans=n+n+k;
	else{
		if(n-k>k-1){
			ans=n+n+n+k-1;
		}else{
			ans=n*4-k;
		}
	}
	cout<<ans<<endl;
	return 0;
}