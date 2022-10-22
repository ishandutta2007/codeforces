#include <bits/stdc++.h>
using namespace std;
#define modulo 988244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000





int main(){
	
	int r,g,b;
	cin>>r>>g>>b;
	
	int ans = 0;
	
	for(int i=0;i<3;i++){
		if(r<i||g<i||b<i)continue;
		int a = i;
		a += (r-i)/3 + (g-i)/3 + (b-i)/3;
		ans = max(ans,a);
	}
	
	cout<<ans<<endl;	
	
    return 0;
}