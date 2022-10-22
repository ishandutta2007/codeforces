#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000

int main(){
	
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++){
		int n;
		cin>>n;
		
		vector<int> a(n);
		for(int j=0;j<n;j++)cin>>a[j];
		
		map<int,int> mp;
		
		for(int j=0;j<n-1;j++){
			mp[abs(a[j]-a[j+1])]++;
		}
		
		if(mp[1]==n-1 ||(mp[1] == n-2 && mp[n-1] == 1)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
	
	
	
	return 0;
}