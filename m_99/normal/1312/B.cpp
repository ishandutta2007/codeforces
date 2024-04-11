#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		
		sort(a.rbegin(),a.rend());
		
		for(int i=0;i<n;i++){
			if(i!=0)cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
	}
	
    return 0;
}