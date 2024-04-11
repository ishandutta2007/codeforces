#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
string s[111];
int cnt[256];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i],cnt[s[i][0]-'a']++;
	int ans=0;
	for(int i=0;i<26;i++){
		int x=cnt[i]/2,y=cnt[i]-x;
		ans+=x*(x-1)/2+y*(y-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}