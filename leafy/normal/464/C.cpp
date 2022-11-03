//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code
//this is a very very long code

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=1e9+7;
typedef long long ll;
string a;
int n;
string q[N];
ll s[15],c[15];
int main(){
	cin>>a;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>q[i];
	for(int i=0;i<10;i++) s[i]=10,c[i]=i;
	for(int i=n;i>=1;i--){	
		int p=q[i][0]-'0';
		ll ss=1,cc=0;
		for(int j=3;j<q[i].size();j++){
			ss=(ss*s[q[i][j]-'0'])%mod;
			cc=(cc*s[q[i][j]-'0']+c[q[i][j]-'0'])%mod;
		}
		s[p]=ss,c[p]=cc;
	}
	ll ans=0;
	for(int i=0;i<a.size();i++) ans=(ans*s[a[i]-'0']%mod+c[a[i]-'0'])%mod;
	cout<<ans;
	return 0;
}