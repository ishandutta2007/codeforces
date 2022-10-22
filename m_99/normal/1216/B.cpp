#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((mod_x)%modulo)
#define Inf 1000000001

int main(){
	
	int n;
	cin>>n;
	
	vector<pair<int,int>> a(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second = i+1;
	}
	
	sort(a.rbegin(),a.rend());
	
	int ans = 0;
	
	for(int i=0;i<n;i++){
		ans += i*a[i].first+1;
	}
	
	cout<<ans<<endl;
	
	for(int i=0;i<n;i++){
		if(i!=0)cout<<' ';
		cout<<a[i].second;
	}
	cout<<endl;
	
    return 0;
}