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
		
		long long k;
		cin>>k;
		
		int cnt = 0;
		set<int> S;
		
		for(int i=0;i<n;i++){
			long long a;
			cin>>a;
			
			for(int j=0;j<60;j++){
				if(a%k==1){
					S.insert(j);
				}
				if(a%k!=0){
					cnt++;
				}
				a/=k;
			}
		}
		if(S.size()==cnt){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
    return 0;
}