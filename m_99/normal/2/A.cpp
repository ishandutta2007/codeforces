#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	int n;
	cin>>n;
	
	vector<pair<string,int>> V(n);
	for(int i=0;i<n;i++)cin>>V[i].first>>V[i].second;
	
	map<string,int> mp;
	for(int i=0;i<n;i++){
		mp[V[i].first]+=V[i].second;
	}
	
	int maxi = 0;
	for(auto a:mp){
		maxi = max(maxi,a.second);
	}
	
	set<string> S;
	for(auto a:mp){
		if(maxi==a.second)S.insert(a.first);
	}
	
	mp.clear();
	for(int i=0;i<n;i++){
		mp[V[i].first]+=V[i].second;
		if(S.count(V[i].first)&&mp[V[i].first]>=maxi){
			cout<<V[i].first<<endl;
			break;
		}
	}
	
	
	
	return 0;
}