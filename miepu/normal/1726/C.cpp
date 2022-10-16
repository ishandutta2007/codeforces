#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;


void solve(){
		
	string s;
	int n,m=0;
	cin>>n>>s;
	for(int i=0;i<n*2-1;i++){
		if(s[i]==')'&&s[i+1]==')')
			m++;
	}
	cout<<m+1<<endl;
	
	
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}