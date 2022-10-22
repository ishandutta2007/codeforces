#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n,q;
	cin>>n>>q;
	
	
	vector<int> a(n);
	vector<int> cnt(200000,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
		cnt[a[i]]++;
	}
	int ans = 0;
	set<int> S;
	int last = 0;
	for(int i=0;i<n;i++){
		S.insert(a[i]);
		cnt[a[i]]--;
		if(cnt[a[i]]==0){
			S.erase(a[i]);
		}
		if(S.size()==0){
			map<int,int> mp;
			for(int j=last;j<=i;j++){
				mp[a[j]]++;
			}
			int K = Inf;
			for(auto x:mp){
				K = min(K,(i-last+1)-x.second);
			}
			ans += K;
			
			
			last = i+1;
		}
	}
	
	cout<<ans<<endl;
	
		
	
	
	return 0;
}