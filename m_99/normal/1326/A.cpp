#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		
		string S(n,'3');
		S[0] = '5';
		cout<<S<<endl;
	}
	
    return 0;
}