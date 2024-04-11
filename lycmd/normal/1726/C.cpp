#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
string s;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>s;
		int res=1;
		for(int i=1;i<n+n;i++)
			res+=s[i-1]=='('&&s[i]=='(';
		cout<<res<<"\n";
	}
	return 0;
}