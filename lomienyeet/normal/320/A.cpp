#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ff first
#define ss second
#define pb push_back
#define multitest int T;cin>>T;while(T--)solve();
void solve(){
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]!='1'&&s[i]!='4'){
			cout<<"NO\n";
			return;
		}
	}
	for(int i=0;i<s.length();i++){
		if(s[i]=='4'){
			cout<<"NO\n";
			return;
		}
		else{
			if(s[i+1]=='1')continue;
			else{
				if(s[i+2]=='1')i++;
				else i+=2;
			}
		}
	}
	cout<<"YES\n";
}
int main(){
	//multitest
	solve();
	return 0;
}