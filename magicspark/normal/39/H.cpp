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
int main(){
	cin>>n;
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++){
			if(i*j>=n)cout<<(i*j)/n;
			cout<<(i*j)%n;
			if(j==n-1)cout<<endl;else cout<<" ";
		}
	return 0;
}