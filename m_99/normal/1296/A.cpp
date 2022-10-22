#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int odd = 0;
		int even = 0;
		
		int n;
		cin>>n;
		
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			if(a%2==0)even++;
			else odd++;
		}
		
		if(odd==0)cout<<"NO"<<endl;
		else if(odd%2==1)cout<<"YES"<<endl;
		else if(even==0)cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
		}
	}
	
    return 0;
}