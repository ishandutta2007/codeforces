#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		string S;
		cin>>S;
		
		vector<int> ind;
		ind.push_back(-1);
		
		for(int i=0;i<S.size();i++){
			if(S[i]=='R'){
				ind.push_back(i);
			}
		}
		ind.push_back(S.size());
		
		int ans = 0;
		for(int i=1;i<ind.size();i++){
			ans = max(ans,ind[i]-ind[i-1]);
		}
		
		cout<<ans<<endl;
	}
		
	
	return 0;
}