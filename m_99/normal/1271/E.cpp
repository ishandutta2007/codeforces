#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

long long k,n;

long long is_ok(long long x){
	if(x>n)return 0;
	long long cnt = 0;
	if(x%2==0){
		for(long long i=0;true;i++){
			long long l = x*((long long)1<<i);
			long long r = l + ((long long)1<<(i+1))-1;
			if(l>n){
				break;
			}
			else if(r<=n){
				cnt += r-l+1;
			}
			else{
				cnt += n-l+1;
				break;
			}
		}
	}
	else{
		cnt = is_ok(x*2)+1;
	}
	return cnt;
}

int main(){
	cin>>n>>k;

	
	long long ok1 = 0;
	long long ng1 = 1000000000000000000;
	while(ng1-ok1>1){
		long long mid = (ok1+ng1)/2;
		if(is_ok(mid*2)>=k)ok1=mid;
		else ng1=mid;
	}
	
	long long ok2 = 0;
	long long ng2 = 1000000000000000000;
	while(ng2-ok2>1){
		long long mid = (ok2+ng2)/2;
		if(is_ok(mid*2+1)>=k)ok2=mid;
		else ng2=mid;
	}
	
	cout<<max(ok1*2,ok2*2+1)<<endl;
	
	return 0;
}