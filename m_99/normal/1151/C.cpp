#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(x) (((long long)x)%modulo)

long long get(long long a){
	long long odd = 0;
	long long even = 0;
	long long x = 1;
	while(true){
		if(a>=x){
			odd=mod(odd+x);
			a-=x;
		}
		else{
			odd=mod(odd+a);
			break;
		}
		x*=2;
		if(a>=x){
			even=mod(even+x);
			a-=x;
		}
		else{
			even=mod(even+a);
			break;
		}
		x*=2;
	}
	long long ret = mod(odd*odd);
	ret = mod(ret+mod((even*even+even)));
	return ret;
}


int main(){
	long long l,r;
	cin>>l>>r;
	long long ans = get(r)-get(l-1);
	if(ans<0)ans+=modulo;
	
	cout<<ans<<endl;
	
	return 0;
}