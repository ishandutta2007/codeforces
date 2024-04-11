#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

long long num(long long a){
	long long ret = 0;
	while(a!=0){
		if(a%2==1)ret++;
		a/=2;
	}
	return ret;
}

int main(){
    
	long long n,p;
	cin>>n>>p;
	
	for(int i=1;i<=35;i++){
		if(num(n-p*i)<=i&&i<=n-p*i){
			cout<<i<<endl;
			return 0;
		}
	}
	
	cout<<-1<<endl;
	
    return 0;
}