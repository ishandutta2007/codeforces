#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		
		vector<int> a(n);
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		
		bool f = false;
		
		for(int j=1;j<n;j++){
			if(abs(a[j] - a[j-1])>=2){
				cout<<"YES"<<endl;
				cout<<j<<' '<<j+1<<endl;
				f=true;
				break;
			}
		}
		if(!f)cout<<"NO"<<endl;
		
	}
	
    return 0;
}