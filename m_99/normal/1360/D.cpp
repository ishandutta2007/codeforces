#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n,k;
		cin>>n>>k;
		
		int ans  =Inf;
		vector<int> Y;
		for(int i=1;i*i<=n;i++){
			if(n%i==0){
				Y.push_back(i);
				Y.push_back(n/i);
			}
		}
		
		for(int i=0;i<Y.size();i++){
			if(Y[i]>k)continue;
			ans = min(ans,n/Y[i]);
		}
		
		cout<<ans<<endl;
	}
	
	return 0;	
}