#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
string s;ll n,sum=0;
int main(){
	cin>>n>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]%2==0){
			sum+=(ll)(i+1);
		}
	}
	cout<<sum<<endl;
	return 0;
}