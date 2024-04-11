#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		
		long long ans = b;
		a-= b;
		if(a<=0){
			cout<<ans<<endl;
			continue;
		}
		if(c-d<=0){
			cout<<-1<<endl;
			continue;
		}
		ans += c * ((a+(c-d-1))/(c-d));
		cout<<ans<<endl;
	}
	
	return 0;
}