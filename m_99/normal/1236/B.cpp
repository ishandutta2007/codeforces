#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

//ab
int beki(int a,int b){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=mod(x*a);
		}
		a=mod(a*a);
		b>>=1;
	}
	return x;
}

int main(){
	
	int n,m;
	cin>>n>>m;
	
	int ans = beki(2,m);
	ans = mod(ans - 1);
	ans = beki(ans,n);
	
	cout<<ans<<endl;
	

	
	
    return 0;
}