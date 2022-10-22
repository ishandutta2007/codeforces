#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int a,b,c,r;
		cin>>a>>b>>c>>r;
		if(a>b)swap(a,b);
		int x = c-r;
		int y = c+r;
		
		x = max(x,a);
		y = min(y,b);
		int ans = b-a;
		if(x<=y){
			ans -= y-x;
		}
		cout<<ans<<endl;
		
	}
	
	
    return 0;
}