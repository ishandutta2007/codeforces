#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000.0



int main(){
	
	int n;
	cin>>n;
	int S = 0;
	for(int i=1;true;i++){
		S += i;
		n-=S;
		if(n<0){
			cout<<i-1<<endl;
			return 0;
		}
	}
	
    return 0;
}