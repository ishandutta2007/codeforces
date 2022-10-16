#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	string s;cin>>s;
	int n=s.size();
	if(s[n-1]=='A'){
		cout<<"No"<<endl;
		return ;
	}	
	int cnt=0;
	for(auto x:s){
		if(x=='A')cnt++;
		else cnt--;
		if(cnt<0){
		cout<<"No"<<endl;
		return ;
	}	
	}
	cout<<"Yes"<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}