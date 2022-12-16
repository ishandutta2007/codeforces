#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n,a,b;
	cin>>n>>a>>b;
	b*=5;
	LL ans=n;
	for(int i=0;i<10000000;i++){
		if(i*a<=n){
			ans=min(ans,(n-i*a)%b);
		}
	}
	cout<<ans<<endl;
	return 0;
}