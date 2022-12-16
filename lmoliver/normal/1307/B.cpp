#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ceil(LL a,LL b){
	return (a+b-1)/b;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		LL n,x;
		cin>>n>>x;
		LL ans=x==0?0:1e18;
		for(int i=0;i<n;i++){
			LL a;
			cin>>a;
			ans=min(ans,x==a?1:x<a?2:ceil(x,a));
		}
		cout<<ans<<endl;
	}
	return 0;
}