#include <bits/stdc++.h>
using namespace std;
#define modulo m
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n,m;
	cin>>n>>m;
		
	vector<int> kaijou(2*n,1);
	
	for(int i=1;i<kaijou.size();i++){
		kaijou[i] = mod(kaijou[i-1] * i);
	}
	
	int ans = 0;
	
	for(int i=1;i<=n;i++){
		int x = n-i+1;
		x = mod(x * (n-i+1));
		x = mod(x * kaijou[i]);
		x = mod(x * kaijou[n-i]);
		ans = mod(ans + x);
	}
	
	cout<<ans<<endl;
	
	
    return 0;
}