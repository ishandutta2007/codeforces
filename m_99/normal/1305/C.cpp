#include <bits/stdc++.h>
using namespace std;
#define modulo m
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<int> a(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	if(n>m+10){
		cout<<0<<endl;
		return 0;
	}
	
	int ans = 1;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans = mod(ans * mod(abs(a[i]-a[j])));
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}