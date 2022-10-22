#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){
	
	int n,d;
	cin>>n>>d;
	
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long ans = 0;
	for(int i=0;i<n;i++){
		auto it = upper_bound(a.begin(),a.end(),a[i]+d);
		long long c = distance(a.begin(),it);
		c--;
		c-=i;
		ans += (c*(c-1))/2;
	}
	
	cout<<ans<<endl;
	
    return 0;
}