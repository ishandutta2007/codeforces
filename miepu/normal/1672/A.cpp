#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;
	int s=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		s+=x-1;
	}
	if(s&1)cout<<"errorgorn"<<endl;
	else cout<<"maomao90"<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}