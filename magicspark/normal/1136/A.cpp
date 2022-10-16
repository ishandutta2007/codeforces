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
int l[111],r[111];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>l[i]>>r[i];
	int k;cin>>k;
	for(int i=0;i<n;i++){
		if(l[i]<=k&&k<=r[i]){
			return printf("%d\n",n-i)*0;
		}
	}
	printf("%d\n",0);
	return 0;
}