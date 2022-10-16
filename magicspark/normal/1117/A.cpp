#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int a[111111];
signed main(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	int temp=*max_element(a+1,a+n+1);
	int i;
	for(i=1;i<=n;){
		int j=i;
		while(a[j]!=temp&&j<=n)j++,i++;
		while(a[i]==a[j]&&i<=n)i++;
		ans=max(ans,i-j);
	}
	cout<<ans<<endl;
	return 0;
}