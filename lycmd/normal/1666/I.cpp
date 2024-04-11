#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m;
int ask(int x,int y){
	cout<<"SCAN "<<x<<" "<<y<<endl,cin>>x;
	return x;
}
int dig(int x,int y){
	cout<<"DIG "<<x<<" "<<y<<endl,cin>>x;
	return x;
}
signed main(){
	for(cin>>t;t--;){
		cin>>n>>m;
		int a1=ask(1,1),a2=ask(n,1),at=(a1-a2+2*n+2)/2,
			am=ask(at/2,1),ax=abs(a1-am)/2+1,bx=at-ax,
			b1=a1,b2=2*m+2*bx-am-4,bt=(b1-b2+2*m+2)/2,
			bm=ask(1,bt/2),ay=abs(b1-bm)/2+1,by=bt-ay;
		if(dig(ax,ay))dig(bx,by);
		else dig(ax,by),dig(bx,ay);
	}
}