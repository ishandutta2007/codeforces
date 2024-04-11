//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n;
llo mod;
llo pre[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>mod;
	pre[0]=1;
	for(llo i=1;i<=n;i++){
		pre[i]=(pre[i-1]*i)%mod;
	}
	llo ans=0;
	for(llo i=1;i<=n;i++){
		llo cur=(n-i+1);
		cur=(cur*pre[i])%mod;
		cur=(cur*pre[n-i])%mod;
			cur=(cur*(n-i+1))%mod;
		ans=(ans+cur)%mod;

		//cout<<cur<<":"<<endl;
	}
	cout<<ans<<endl;





 
	return 0;
}