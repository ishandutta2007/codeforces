#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	int x=0;
	int l=0,r=n-1;
	while(l<r){
		int mid=(l+r)>>1;
		int p=n-mid-1;
		cout<<"+ "<<p<<endl;
		int y;cin>>y;
		if(x!=y)l=mid+1;
		else r=mid;
		l+=p;r+=p;
		if(l>=n)l-=n,r-=n;
		x=y;
	}
	cout<<"! "<<x*n+l%n<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}