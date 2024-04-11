#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;
int n;string s;


void solve(){
	cin>>n>>s;
	int p=count(s.begin(),s.end(),'1');
	if((p&1)||p==0){
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<endl;
	p=0;
	for(int i=0;i<n;i++)if(s[i]=='1')p=(i-1+n)%n;
	for(int i=1;i<n;i++){
		int a=(p+i)%n,b=(p+i+1)%n;
		if(s[b]=='0')cout<<a+1<<' '<<b+1<<'\n';
		else cout<<a+1<<' '<<p+1<<'\n';
	}
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
}