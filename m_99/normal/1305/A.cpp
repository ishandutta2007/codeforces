#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		vector<int> a(n),b(n);
		
		for(int j=0;j<n;j++)cin>>a[j];
		for(int j=0;j<n;j++)cin>>b[j];
		
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		
		for(int j=0;j<n;j++){
			if(j!=0)cout<<' ';
			cout<<a[j];
		}
		cout<<endl;
		
		for(int j=0;j<n;j++){
			if(j!=0)cout<<' ';
			cout<<b[j];
		}
		cout<<endl;
	}
	
	return 0;
}