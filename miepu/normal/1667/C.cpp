#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;
	int res=(n*2+1)/3;
	cout<<res<<endl;
	for(int i=1,j=1;i<=res;i++){
		cout<<i<<' '<<j<<endl;
		if((j+=2)>res)j=2;
	}
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}