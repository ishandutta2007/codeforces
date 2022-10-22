#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		
		long long X = x2-x1+1;
		long long Y = y2-y1+1;
		
		
		cout<<(X-1)*(Y-1)+1<<endl;
	}
	
	return 0;
}