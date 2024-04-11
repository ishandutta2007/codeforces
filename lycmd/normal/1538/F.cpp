#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,l,r;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>l>>r;
		int ans=0;
		for(int k=1000000000,cur=0;k;k/=10)
			ans+=cur=cur*10+r/k%10-l/k%10;
		cout<<ans<<"\n";
	}
}