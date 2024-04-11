#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int fl=1,pr=-N;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		fl&=x>=pr
;pr=x;	}
if(fl)cout<<"NO"<<endl;
else cout<<"YES"<<endl; 
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}