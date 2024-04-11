#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a.begin(),a.end());
	
	for(int i=0;i<n-2;i++){
		int x = a[i];
		int y = a[i+1];
		int z = a[i+2];
		
		if(x+y>z){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	
	cout<<"NO"<<endl;
	
	return 0;
	
}