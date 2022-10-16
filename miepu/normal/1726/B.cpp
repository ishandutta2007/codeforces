#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	if(m<n){
		cout<<"NO"<<endl;return;
	}
	if(n&1){
		cout<<"YES"<<endl;
		for(int i=1;i<n;i++){
			cout<<1<<' ';
		}
		cout<<m-(n-1)<<endl;
		return;
	}
	if(m&1){
		cout<<"NO"<<endl;return;
	}
	cout<<"YES"<<endl; 
	for(int i=1;i<=n-2;i++)cout<<1<<' ';
	cout<<(m-n)/2+1<<' '<<(m-n)/2+1<<endl; 
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;
	cin>>_T;
	while(_T--)solve();
}