#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200001];
main(){
    int t;
	cin>>t;
	while(t--){
        int n;
		cin>>n;
		int ans=0;
		for(int x=1;x<=n;x++)cin>>a[x];
		for(int x=1,y=a[x],z=a[x%n+1],tot=0,q=x;x<=n;ans=max(ans,tot),x++,y=a[x],z=a[x%n+1],tot=0,q=x)
		while(y!=z)y=__gcd(y,a[(q++)%n+1]),z=__gcd(z,a[q%n+1]),tot++;
		cout<<ans<<endl;
	}
}