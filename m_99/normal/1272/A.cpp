#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	
	int Q;
	cin>>Q;
	
	for(int i=0;i<Q;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		long long ans = Inf;
		for(int j=0;j<27;j++){
			int x = j;
			long long aa = a,bb=b,cc=c;
			if(x%3==0){
				aa++;
			}
			else if(x%3==1){
				aa--;
			}
			
			x/=3;
			if(x%3==0){
				bb++;
			}
			else if(x%3==1){
				bb--;
			}
			x/=3;
			if(x%3==0){
				cc++;
			}
			else if(x%3==1){
				cc--;
			}
			ans = min(ans,abs(aa-bb)+abs(bb-cc)+abs(cc-aa));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}