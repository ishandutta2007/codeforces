#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int b,g,n;
	cin>>b>>g>>n;
	
	int ans = 0;
	
	for(int i=0;i<=n;i++){
		int bb = i;
		int gg = n-i;
		
		if(bb>b||gg>g)continue;
		ans++;
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}