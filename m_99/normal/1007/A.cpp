#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000



int main(){
    
	int n;
	cin>>n;
	
	vector<int> a(n);
	multiset<int> S;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		S.insert(a[i]);
	}
	
	sort(a.begin(),a.end());
	
	int ans = 0;
	
	for(int i=0;i<n;i++){
		auto it = S.upper_bound(a[i]);
		if(it==S.end())break;
		ans++;
		S.erase(it);
	}
	
	cout<<ans<<endl;
    
    return 0;
}