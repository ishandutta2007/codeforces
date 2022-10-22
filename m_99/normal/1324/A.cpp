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
		
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		bool f = true;
		
		for(int i=0;i<n;i++){
			if(a[0]%2!=a[i]%2){
				f=false;
				break;
			}
		}
		
		if(f){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
		
	
	return 0;
}