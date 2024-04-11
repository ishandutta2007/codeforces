#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,m,k;cin>>n>>m>>k;
	int s0=0,s1=0;
	int f0=1,f1=1;
	while(k--){
		int x;cin>>x;
		if(x>=n*2)s0+=x/n,f0&=x/n==2;
		if(x>=m*2)s1+=x/m,f1&=x/m==2; 
	}
	if(s0>=m&&(!f0||!(m&1)))
		cout<<"Yes"<<endl;
	else 
	if(s1>=n&&(!f1||!(n&1)))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}