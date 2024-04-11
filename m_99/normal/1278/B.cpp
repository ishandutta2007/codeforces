#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int a,b;
		cin>>a>>b;
		
		int k = max(a,b)-min(a,b);
		int ok = 100000;
		int ng = -1;
		while(ok-ng>1){
			long long mid = (ok+ng)/2;
			long long c = (mid * (mid+1))/2;
			if(c>=k)ok=mid;
			else ng=mid;
		}
		while(true){
			long long X = ok;
			long long c = (X * (X+1))/2;
			if(abs(c-k)%2==0)break;
			ok++;
		}
		
		cout<<ok<<endl;
		
	}
	
	return 0;
}