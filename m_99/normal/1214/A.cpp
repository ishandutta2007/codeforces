#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int n,d,e;
	cin>>n>>d>>e;
	
	e*=5;
	
	int ans = Inf;
	
	for(int i=0;true;i++){
		if(i*d>n)break;
		
		int a = i*d;
		a = n-a;
		ans = min(ans,a%e);
		
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}