#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000

long long get(vector<long long> x){
	long long ret = x.size();
	long long mini = Inf;
	for(int i=0;i<x.size();i++){
		mini = min(mini,x[i]);
	}
	for(int i=0;i<x.size();i++){
		x[i] -= mini;
	}
	long long temp = mini;
	
	vector<vector<long long>> y(1,vector<long long>());
	for(int i=0;i<x.size();i++){
		if(x[i]==0)y.push_back(vector<long long>());
		else y.back().push_back(x[i]);
	}
	
	for(int i=0;i<y.size();i++){
		if(y[i].size()==0)continue;
		temp += get(y[i]);
	}
	
	return min(temp,ret);
	
}

int main(){
	
	int n;
	cin>>n;
	
	vector<long long> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	
	vector<vector<long long>> x(1,vector<long long>());
	for(int i=0;i<n;i++){
		if(a[i]==0)x.push_back(vector<long long>());
		else x.back().push_back(a[i]);
	}
	
	long long ans = 0;
	for(int i=0;i<x.size();i++){
		if(x[i].size()==0)continue;
		ans += get(x[i]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}