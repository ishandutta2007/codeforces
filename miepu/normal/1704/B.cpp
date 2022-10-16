#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,k;cin>>n>>k;
	int res=0;
	int mx=-1e9,mn=1e9;
	while(n--){
		int x;cin>>x;
		mx=max(mx,x);
		mn=min(mn,x);
		if(mx-mn>k*2){
			res++;
			mn=mx=x;
		}
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}