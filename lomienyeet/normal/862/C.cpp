#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int letsgo=(1ll<<17);
signed main(){
	int n,x;
	cin>>n>>x;
	if(n==1)cout<<"YES\n"<<x<<"\n";
	else if(n==2){
		if(!x)cout<<"NO\n";
		else cout<<"YES\n0 "<<x<<"\n";
	}
	else{
		cout<<"YES\n";
		for(int i=0;i<n-3;i++){
			cout<<i<<" ";
			x^=i;
		}
		// ok, time for ceil(log2(1e5))=17
		cout<<(letsgo^x)<<" "<<(letsgo<<1)<<" "<<(letsgo^(letsgo<<1))<<"\n";
	}
}