#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL b,g,n;
	cin>>b>>g>>n;
	b=min(b,n);
	g=min(g,n);
	LL ans=max(b+g-n+1,1LL);
	cout<<ans<<endl;
	return 0;
}