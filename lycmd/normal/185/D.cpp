#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,k,l,r,p;
int qpow(int x,int y,int p){
	return y?qpow(x*x%p,y>>1,p)*(y&1?x:1)%p:1;
}
int ppow(int l){
	return k%p?qpow(k,qpow(2,l,p-1),p):0;
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;)
		cin>>k>>l>>r>>p,cout<<((ppow(l)==1?qpow(2,r-l+1,p):(ppow(r+1)-1)*qpow(ppow(l)-1,p-2,p)%p+p)%p*(k&1?qpow(qpow(2,r-l,p),p-2,p):1)%p)<<"\n";
}