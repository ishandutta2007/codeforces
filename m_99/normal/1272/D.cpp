#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	vector<pair<int,int>> P;
	
	for(int i=0;i<n;i++){
		int last = i;
		for(int j=last+1;j<n;j++){
			if(a[j] <= a[j-1])break;
			last = j;
		}
		P.emplace_back(i,last);
		i = last;
	}
	
	int ans = 0;
	for(int i=0;i<P.size();i++){
		ans = max(ans,P[i].second - P[i].first + 1);
	}
	
	for(int i=1;i<P.size();i++){
		if(P[i].first==P[i].second){
			if(i==P.size()-1)continue;
			if(a[P[i-1].second] < a[P[i+1].first]){
				ans = max(ans,P[i-1].second - P[i-1].first + 1 + P[i+1].second - P[i+1].first + 1);
			}
		}
		else{
			if(a[P[i-1].second]<a[P[i].first+1]){
				ans = max(ans,P[i-1].second-P[i-1].first + 1 + P[i].second - P[i].first);
			}
		}
	}
	
	for(int i=0;i<P.size()-1;i++){
		if(P[i].first==P[i].second){
			if(i==0)continue;
			if(a[P[i-1].second] < a[P[i+1].first]){
				ans = max(ans,P[i-1].second - P[i-1].first + 1 + P[i+1].second - P[i+1].first + 1);
			}
		}
		else{
			if(a[P[i].second-1]<a[P[i+1].first]){
				ans = max(ans,P[i].second - P[i].first + P[i+1].second - P[i+1].first + 1);
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}