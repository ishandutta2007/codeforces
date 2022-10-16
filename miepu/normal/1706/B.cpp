#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<vector<int>> pos(n+1);
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		pos[x].push_back(i); 
	}
	for(int i=1;i<=n;i++){
		int a=0,b=0;
		for(auto x:pos[i]){
			if(x&1)a=max(a,b+1);
			else b=max(b,a+1);
		}
		cout<<max(a,b)<<' ';
	}cout<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}