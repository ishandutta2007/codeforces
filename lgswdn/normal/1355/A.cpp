#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9; 
int ans;
signed main(){
	int t; cin>>t;
	while(t--){
		int k;
		scanf("%lld%lld",&ans,&k);
		for(int i=2;i<=k;i++){
			int md=10,xd=0,tmp=ans;
			while(tmp){
				md=min(md,tmp%10),xd=max(xd,tmp%10);
				tmp/=10;
			}
			if(md==0) break;
			ans+=md*xd;
		}
		cout<<ans<<std::endl;
	}
	return 0;
}