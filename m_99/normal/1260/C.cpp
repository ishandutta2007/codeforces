#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

long long gcd(long long a, long long b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(){
	
	long long n;
	cin>>n;

	for(long long i=0;i<n;i++){
		long long r,b,k;
		cin>>r>>b>>k;
		long long g = gcd(r,b);
		r/=g;
		b/=g;
		if(r>b)swap(r,b);
		b--;
		long long a = (b+r-1)/r;
		if(a>=k){
			cout<<"REBEL"<<endl;
		}
		else{
			cout<<"OBEY"<<endl;
		}
	}
	
	return 0;
	
}