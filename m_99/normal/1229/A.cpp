#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	int N;
	cin>>N;
	vector<pair<long long,long long>> P(N);
	for(int i=0;i<N;i++){
		cin>>P[i].first;
	}
	for(int i=0;i<N;i++){
		cin>>P[i].second;
	}
	sort(P.begin(),P.end());
	long long ans = 0;
	
	vector<long long> A;
	
	for(int i=1;i<N;i++){
		if(P[i].first!=P[i-1].first)continue;
		A.push_back(P[i].first);
	}
	
	
	for(int i=0;i<N;i++){
		for(int j=0;j<A.size();j++){
			if((P[i].first|A[j])==A[j]){
				ans += P[i].second;
				break;
			}
		}
	}
	
	cout<<ans<<endl;
	
		
	
	
	
	return 0;
}