#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000

int main(){
	
	int T;
	cin>>T;
	
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		long long x;
		cin>>x;
		
		long long maxi_A=0,maxi_B=0;
		for(int i=0;i<n;i++){
			long long d,h;
			cin>>d>>h;
			maxi_A = max(maxi_A,d-h);
			maxi_B = max(maxi_B,d);
		}
		x-=maxi_B;
		if(x<=0){
			cout<<1<<endl;
			continue;
		}
		if(maxi_A<=0){
			cout<<-1<<endl;
			continue;
		}
		cout<<((x+maxi_A-1)/maxi_A)+1<<endl;
		
	}
	
	return 0;
}