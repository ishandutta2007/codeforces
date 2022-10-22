#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long p,f,cntS,cntW,s,w;
		cin>>p>>f>>cntS>>cntW>>s>>w;
		if(s>w){
			swap(s,w);
			swap(cntS,cntW);
		}
		long long ans = p/s + f/s;
		if(ans<cntS){
			cout<<ans<<endl;
			continue;
		}
		ans = cntS;
		for(long long i=0;i<=cntS;i++){
			long long P = p-i*s;
			long long F = f-(cntS-i)*s;
			if(P<0||F<0)continue;
			long long W = min(cntW,P/w + F/w);
			ans = max(ans,cntS + W);
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}