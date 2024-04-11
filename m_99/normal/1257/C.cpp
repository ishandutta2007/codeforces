#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		
		map<int,vector<int>> mp;
		for(int j=0;j<n;j++){
			int a;
			cin>>a;
			mp[a].push_back(j);
		}
		int ans = Inf;
		for(auto a:mp){
			if(a.second.size()==1)continue;
			for(int j=1;j<a.second.size();j++){
				ans = min(ans,a.second[j] - a.second[j-1]+1);
			}
		}
		if(ans==Inf)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	
	
    return 0;
}