#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,p,n,ans;
int qpow(int x,int y=p-2){
	return y?qpow(x*x%p,y>>1)*(y&1?x:1)%p:1;
}
signed main(){
	cin>>a>>b>>p>>n;
	int t=qpow(a),ip=qpow(p-1),k=1;
	for(int i=1;i<p;i++){
		int x=((k=k*t%p)*b%p-i+p)%p*ip%p;
		if(x*(p-1)<=n-i)
			ans+=((n-i)/(p-1)-x)/p+1;
	}
	cout<<ans<<"\n";
}//