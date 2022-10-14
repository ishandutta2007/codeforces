#include<bits/stdc++.h>
#define int long long
using namespace std;
int f,t,t0,a1,t1,p1,a2,t2,p2,ans=LLONG_MAX,x;
signed main(){
	cin>>f>>t>>t0>>a1>>t1>>p1>>a2>>t2>>p2;
	if(t1<t2)
		swap(a1,a2),swap(t1,t2),swap(p1,p2);
	for(int i=0;i<=f/a2+1;i++){
		int r=f-min(a2*i,f),w=t-(f-r)*t2;
		if(w>=t0*r)
			ans=min(ans,p2*i);
		else if(w>=t1*r){
			x=(t0*r-w-1)/(t0-t1)+1;
			if(x<=r)
				ans=min(ans,p2*i+((x-1)/a1+1)*p1);
		}
	}
	cout<<(ans<LLONG_MAX?ans:-1)<<"\n";
}