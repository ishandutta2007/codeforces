#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int n;
	cin>>n;
	
	map<int,long long> x,y;
	map<pair<int,int>,long long> xy;
	
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		x[a]++;
		y[b]++;
		xy[make_pair(a,b)]++;
	}
	
	long long ans = 0LL;
	
	for(auto a:x){
		ans += a.second * (a.second-1)/2;
	}
	
	for(auto a:y){
		ans += a.second * (a.second-1)/2;
	}
	
	for(auto a:xy){
		ans -= a.second * (a.second-1)/2;
	}
	
	cout<<ans<<endl;
	
	return 0;
}