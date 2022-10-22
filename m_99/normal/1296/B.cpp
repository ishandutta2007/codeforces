#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long s;
		cin>>s;
		
		long long ans = 0;
		
		while(true){
			ans += (s/10)*10;
			s = (s%10) + (s/10);
			if(s<10)break;
		}
		ans += s;
		
		cout<<ans<<endl;
	}
	
    return 0;
}