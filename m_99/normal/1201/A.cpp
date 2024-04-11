#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x))%modulo)
#define Inf 10000000000000000


int main(){
	
	int n,m;
	cin>>n>>m;
	vector<string> s(n);
	long long ans = 0;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	
	vector<int> a(m);
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<m;i++){
		map<char,int> mp;
		for(int j=0;j<n;j++){
			mp[s[j][i]]++;
		}
		int k = 0;
		for(auto x:mp){
			k = max(x.second,k);
		}
		
		ans += k*a[i];
	}
	
	cout<<ans<<endl;
		
	
			
			
	
	
	return 0;
}