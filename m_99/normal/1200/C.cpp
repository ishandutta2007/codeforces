#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x))%modulo)
#define Inf 10000000000000000

long long gcd(long long a, long long b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(){
	
	long long n,m,q;
	cin>>n>>m>>q;
	
	long long g = gcd(n,m);
	
	long long p1 = n/g;
	long long p2 = m/g;
	
	for(int i=0;i<q;i++){
		long long sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		sy--;ey--;
		long long a,b;
		if(sx==1){
			a = sy / p1;
		}
		else{
			a = sy / p2;
		}
		
		if(ex==1){
			b = ey / p1;
		}
		else{
			b = ey / p2;
		}
		
		if(a==b){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
		
		
	
	
		
	
	return 0;
}