#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ff first
#define ss second
#define pb push_back
#define multitest int T;cin>>T;while(T--)solve();
void solve(){
	int T,S,X;
	cin>>T>>S>>X;
	if(X<T)cout<<"NO";
	else{
		X-=T;
		if(X==0)cout<<"YES";
		else if(X<S)cout<<"NO";
		else if(X%S==0||X%S==1)cout<<"YES";
		else cout<<"NO\n";
	}
}
int main(){
	//multitest
	solve();
	return 0;
}