#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000

int main(){
	long long W;
	cin>>W;
	vector<long long> cnt(8);
	rep(i,8)scanf("%lld",&cnt[i]);
	
	vector<int> v,w;
	
	rep(i,8){
		rep(j,10){
			if(cnt[i]==0)continue;
			cnt[i]--;
			w.push_back(i+1);
			v.push_back(i+1);
		}
	}
	
	bitset<1000> B;
	B[0] = 1;
	rep(i,w.size()){
		B |= B<<w[i];
	}
	long long ans = 0LL;
	rep(i,1000){
		if(B[i]){
			long long ww = W - i;
			if(ww<0)continue;
			rep(j,8){
				ww -= min(cnt[j],ww/(j+1))*(j+1);
			}
			ans = max(ans,W-ww);
		}
	}
	
	cout<<ans<<endl;
			
	
	return 0;
}