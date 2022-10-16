#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	string s;char c;
	cin>>s>>c;
	for(int i=0;i<s.size();i++){
		if(s[i]==c){
			if(!(i&1)){cout<<"Yes"<<endl;return;}
		}
	}
	cout<<"No"<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}