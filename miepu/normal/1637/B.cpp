#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;
	int res=0;
	for(int i=1;i<=n;i++){
		res+=i*(n-i+1);
		int x;cin>>x;
		if(x==0)res+=i*(n-i+1);
	}
	cout<<res<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}