#include <bits/stdc++.h>
using namespace std;
#define modulo 100000
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int h,m;
		cin>>h>>m;
		
		cout<<(23-h)*60 + (60-m)<<endl;
	}
	
    return 0;
}