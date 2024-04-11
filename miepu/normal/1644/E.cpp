#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int res=n*n+1;
	int i,h=1,c=1;
	for(i=0;i<s.size()&&s[i]==s[0];i++)
		res-=n-1;
	if(i==s.size()){
		cout<<n<<endl;
		return ; 
	}
	for(;i<s.size();i++){
		res++;
		if(s[i]=='R')h++;
		else c++;
	}
	res-=h*c;
	cout<<res<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}