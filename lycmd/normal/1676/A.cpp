#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
string s;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>s;
		cout<<(s[0]+s[1]+s[2]==s[3]+s[4]+s[5]?"YES\n":"NO\n");
	}
	return 0;
}