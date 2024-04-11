#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

int main(){
	
	int n;
	cin>>n;
	
	vector<int> u(n),v(n);
	
	vector<int> cnt(n,0);
	
	for(int i=0;i<n-1;i++){
		cin>>u[i]>>v[i];
		u[i]--;
		v[i]--;
		
		cnt[u[i]]++;
		cnt[v[i]]++;
	}
	
	set<int> S;
	
	for(int i=0;i<n;i++){
		if(cnt[i]==1)S.insert(i);
	}
	
	vector<int> ans(n-1,-1);
	vector<int> X(n-1);
	for(int i=0;i<n-1;i++){
		X[i] = n-2-i;
	}
	
	for(int i=0;i<n-1;i++){
		if(S.count(u[i])||S.count(v[i])){
			ans[i] = X.back();
			X.pop_back();
		}
	}
	
	for(int i=0;i<n-1;i++){
		if(ans[i]==-1){
			ans[i] = X.back();
			X.pop_back();
		}
	}
	
	for(int i=0;i<n-1;i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}