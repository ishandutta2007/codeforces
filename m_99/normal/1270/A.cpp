#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n,k1,k2;
		cin>>n>>k1>>k2;
		bool f = false;
		for(int j=0;j<k1;j++){
			int a;
			cin>>a;
			if(a==n)f = true;
		}
		for(int j=0;j<k2;j++){
			int a;
			cin>>a;
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
    return 0;
}