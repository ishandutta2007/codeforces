#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,x;
int	cnt[3];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		cnt[x]++;
	}
	bool add=false;
	if(cnt[1]&&cnt[1]%2==0)add=true,cnt[1]--;
	if(cnt[2])cout<<2<<" ",cnt[2]--;
	while(cnt[1]--)cout<<1<<" ";
	while(cnt[2]--)cout<<2<<" ";
	if(add)cout<<1;
	return 0;
}