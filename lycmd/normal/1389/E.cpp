#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,m,d,w;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>m>>d>>w;
		int i=w/__gcd(w,d-1),p=(min(m,d)-1)/i;
		cout<<p*min(m,d)-i*p*(p+1)/2<<"\n";
	}
}