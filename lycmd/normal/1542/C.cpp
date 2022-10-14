#include<bits/stdc++.h>
#define int long long
using namespace std;
int const MOD=1000000007;
int t,n;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int lcm(int x,int y){
	return x/gcd(x,y)*y;
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		int ans=0,cur=1;
		for(int i=2;cur<=n;i++){
			ans=(ans+i*(n/cur-n/(cur*i/gcd(cur,i)))%MOD)%MOD;
			cur=lcm(cur,i);
		}
		cout<<ans<<"\n";
	}
}//