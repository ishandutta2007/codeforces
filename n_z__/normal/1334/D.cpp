#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t,n,l,r,now,x,y;
	cin>>t;
	while(t--){
		for(cin>>n>>l>>r,x=(n-1)*2,now=0;x;now+=x,x-=2)
		for(y=max(now+1,l);y<=min(r,now+x);y++)
		if(y%2)cout<<n-x/2<<" ";else cout<<(y-now)/2+n-x/2<<" ";
		if(now==r-1)cout<<1;
		cout<<endl;
	}
}