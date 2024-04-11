#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	long long n;
	cin>>n;
	
	vector<int> a(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i] /= abs(a[i]);
	}
	
	map<long long,long long> mp;
	mp[1]++;
	int now = 1;
	
	for(int i=0;i<n;i++){
		now*=a[i];
		mp[now]++;
	}
	
	long long ans2 = (mp[1]*(mp[1]-1))/2 + (mp[-1]*(mp[-1]-1))/2;
	long long ans1 = (n*(n+1))/2 - ans2;
	
	cout<<ans1<<' '<<ans2<<endl;
		
	
    return 0;
}