#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ff first
#define ss second
#define pb push_back
#define multitest int T;cin>>T;while(T--)solve();
const int mod=1e9+7;
int bigpow(int a,int b){
	int re=1;
	while(b){
		if(b&1)re=(re*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return re;
}
void solve(){
	string s;
	cin>>s;
	set<string> se;
	for(int i=0;i<s.size();i++){
		string temp=s.substr(i,s.size()-i)+s.substr(0,i);
		se.insert(temp);
	}
	cout<<se.size();
}
int main(){
	//multitest
	solve();
	return 0;
}