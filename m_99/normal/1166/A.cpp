#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000

long long combi(long long n){
	return n*(n-1)/2;
}

int main(){
    
	int n;
	cin>>n;
	
	map<char,long long> mp;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		mp[s[0]]++;
	}
	
	long long ans = 0;
	
	for(auto a:mp){
		long long x = a.second;
		ans += combi(x/2);
		ans += combi((x+1)/2);
	}
	
	cout<<ans<<endl;
    
    return 0;
}