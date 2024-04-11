#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int mini = 10000;
		int maxi = -1;
		for(int j=0;j<n;j++){
			if(s[j]=='1'){
				mini=min(j,mini);
				maxi=max(j,maxi);
			}
		}
		if(maxi==-1){
			cout<<n<<endl;
		}
		else{
			int a = min(mini,n-1-maxi);
			cout<<max(n,2*(n-a))<<endl;
		}
	}
	
	
	
	
	
    return 0;
}