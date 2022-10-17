#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int c=count(s.begin(),s.end(),s[0]);
	if(c==n){
		cout<<n<<endl;
		return;
	}
	int t=(n-1)/2;
	while(t&&s[t]==s[n/2])t--;
	cout<<((n-1)/2-t)*2-(n&1)<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}