#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int t;
	cin>>t;
	
	double PI = acos(-1.0);
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		double ans = 0.0;
		for(int i=0;i<n;i++){
			ans += sin(PI/(double)n * i);
		}
		cout<<fixed<<setprecision(10)<<ans<<endl;
	}
	
	return 0;
}