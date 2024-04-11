#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	string s;cin>>s;
	if(s.size()==2)cout<<s[1]<<endl;
	else{
		cout<<*min_element(s.begin(),s.end())<<endl;
	} 
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}