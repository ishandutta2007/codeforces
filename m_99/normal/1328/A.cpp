#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int a,b;
		cin>>a>>b;
		
		int x;
		
		x = (a+b-1)/b;
		x*=b;
		cout<<x-a<<endl;
	}

    return 0;
}