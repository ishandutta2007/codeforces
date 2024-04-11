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
int n,k;
signed main(){
	cin>>n>>k;
	if(n>k*(k-1)){
		puts("nO");
		return 0;
	}else{
		int cnt=0;
		puts("yES");
		for(int i=1;i<=k;i++)
			for(int j=i+1;j<=k;j++){
				cout<<i<<" "<<j<<endl;
				cnt++;
				if(cnt==n)return 0;
				cnt++;
				cout<<j<<" "<<i<<endl;
				if(cnt==n)return 0;
			}
	}
	return 0;
}