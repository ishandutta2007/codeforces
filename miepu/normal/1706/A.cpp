#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n,m;cin>>n>>m;
	string res(m,'B');
	while(n--){
		int x;cin>>x;
		x=min(x,m-x+1);
		x--;
		if(res[x]=='B')res[x]='A';
		else res[m-x-1]='A';
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}