#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int cnt=-N,res=0;
	for(auto x:s){
		if(x=='0'){
			res+=max(0ll,cnt);
			cnt=2;
		}else cnt--;
	}cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}