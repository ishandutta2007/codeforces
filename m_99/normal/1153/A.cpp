#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000



int main() {
	
	int n,t;
	cin>>n>>t;
	
	int ans = -1;
	int maxi = 1000000000;
	
	for(int i=0;i<n;i++){
		int s,d;
		cin>>s>>d;
		
		int k;
		for(int j=s;true;j+=d){
			if(j>=t){
				if(maxi>j){
					maxi = j;
					ans = i;
				}
				break;
			}
		}
	}
	
	cout<<ans+1<<endl;
	
    return 0;
}