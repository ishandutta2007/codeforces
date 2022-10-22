#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		map<int,int> mp;
		rep(i,n){
			int a;
			scanf("%d",&a);
			mp[a]++;
		}
		
		vector<int> cnt;
		for(auto a:mp){
			cnt.push_back(a.second);
		}
		
		sort(cnt.rbegin(),cnt.rend());
		
		int erased = 0;
		int ans = Inf;
		for(int i=1;i<=n;i++){
			while(cnt.size()>0 && cnt.back() < i){
				erased += cnt.back();
				cnt.pop_back();
			}
			ans = min(ans,(int)(erased + (n-erased) - i*(int)cnt.size()));
		}
		
		printf("%d\n",ans);
				
		
	}
	
    return 0;
}