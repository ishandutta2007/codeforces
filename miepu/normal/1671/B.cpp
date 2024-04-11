#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int cnt=0,mx=0;
	int n;cin>>n;
	int pr;cin>>pr;
	for(int i=1;i<n;i++){
		int x;cin>>x;
		cnt+=(x-pr-1);
		pr=x;
	}
	if(cnt>2)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}