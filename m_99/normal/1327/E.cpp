#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


//ab
int beki(int a,int b,int M = modulo){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=((long long)x*a)%M;
		}
		a=((long long)a*a)%M;
		b>>=1;
	}
	return x;
}


//a
int gyakugen(int a){
	return beki(a,modulo-2);
}

int main() {
	
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		if(i!=1)cout<<' ';
		if(i==n){
			cout<<10;
			continue;
		}
		
		int ans = 0;
		
		ans = 90;
		ans = mod(ans * beki(10,n-1-i));
		ans = mod(ans * 2);
		
		if(n-i>=2){
			int temp = 810;
			temp = mod(temp * beki(10,n-2-i));
			temp = mod(temp * (n-i-2+1));
			ans = mod(ans + temp);
		}
		
		cout<<ans;
	}
				
    return 0;
}