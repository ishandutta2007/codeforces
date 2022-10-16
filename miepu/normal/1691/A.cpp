#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int c1=0,c2=0;
	int n;cin>>n;
	while(n--){
		int x;cin>>x;
		if(x&1)c1++;
		else c2++;
	}
	cout<<min(c1,c2)<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}