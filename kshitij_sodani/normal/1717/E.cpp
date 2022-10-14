#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;
llo n;
const llo mod=1e9+7;
vector<llo> pre[100001];
llo vis[100001];

llo cal[100001];
vector<llo> pre2[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	vis[1]=3;
	for(llo i=1;i<=1e5;i++){
		if(vis[i]==0){
			vis[i]=2;
			pre[i].pb(i);
			for(llo j=2*i;j<=1e5;j+=i){
				pre[j].pb(i);
				vis[j]=1;
			}
		}
		for(llo j=i;j<=1e5;j+=i){
			pre2[j].pb(i);
		}
	}
	for(llo i=2;i<=1e5;i++){
		//cal[i]=cal[i-1];
		llo x=i;
		for(auto j:pre[i]){
			x=(x*(j-1));
		}
		for(auto j:pre[i]){
			x/=j;
		}
		
		cal[i]+=x;
		cal[i]%=mod;
	}

	llo ans=0;
	for(llo i=2;i<=n-1;i++){
		for(auto j:pre2[i]){
			llo x=i/j;


			llo xx=j*(n-i);
			xx/=__gcd(j,n-i);
			xx%=mod;
			//cout<<i<<":"<<j<<":"<<cal[x]<<":"<<xx*cal[x]<<endl;
			if(x>1){
				ans=(ans+xx*cal[x])%mod;
			}
		}
	}
	cout<<ans<<endl;






	return 0;
}