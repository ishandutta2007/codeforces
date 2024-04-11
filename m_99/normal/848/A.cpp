#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){

	int k;
	cin>>k;
	
	string ans = "";
	rep(i,26){
		ans += 'a'+i;
		for(int j=1;true;j++){
			if(k<j)break;
			k -= j;
			ans += 'a'+i;
		}
	}
	
	cout<<ans<<endl;
	
    return 0;
}