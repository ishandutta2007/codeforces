#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	for(auto&x:a){
		cin>>x;
	} 
	int ans=1e18,res;
	if(n&1){
		res=0;
		for(int i=1;i<n-1;i+=2){
			res+=max(0ll,max(a[i-1],a[i+1])+1-a[i]);
		}
		cout<<res<<endl;
	}
	if(!(n&1)){
		vector<int> f(n),g(n); 
		res=0;
		for(int i=n-2;i>1;i-=2){
			res+=max(0ll,max(a[i-1],a[i+1])+1-a[i]);
			f[i/2]=res;
		}
		ans=res;
		res=0;
		for(int i=1;i<n-1;i+=2){
			res+=max(0ll,max(a[i-1],a[i+1])+1-a[i]);
			ans=min(res+f[(i+3)/2],ans);
		}
		cout<<ans<<endl;
	}
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}