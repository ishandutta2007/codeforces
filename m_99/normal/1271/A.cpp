#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

int main(){
	
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	int ans = 0;
	for(int i=0;i<=d;i++){
		int j = d-i;
		int x = min(i,a);
		int y = min({j,b,c,d});
		ans = max(ans,e*x+f*y);
	}
	
	cout<<ans<<endl;
	
	return 0;
}