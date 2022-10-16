#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int a1,a2,a3,a4;
int main(){
	cin>>a1>>a2>>a3>>a4;
	a3=min(1,a3);
	if(a1==a4&&(a3==0||(a1))){
		cout<<1<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}