#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long a,b,n;
		cin>>a>>b>>n;
		if(a>b)swap(a,b);
		long long ans = 0;
		while(true){
			if(a>n||b>n)break;
			ans++;
			a += b;
			swap(a,b);
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}