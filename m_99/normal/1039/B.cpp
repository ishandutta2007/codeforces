#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000
long long n;
bool check(long long l,long long r){
	cout<<l<<' '<<r<<endl;
	string ret;
	cin>>ret;
	if(ret=="Yes")return true;
	else return false;
}

unsigned long xor128() {
	static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
	unsigned long t=(x^(x<<11));
	x=y; y=z; z=w;
	return (w=(w^(w>>19))^(t^(t>>8)));
}

int main(){

	
	cin>>n;
	
	int k;
	cin>>k;
	
	long long l = 1,r = n+1;
	
	while(true){
		if(r-l>100){
			long long mid = (l+r)/2;
			bool result = check(l,mid);
			if(result){
				r = mid;
			}
			else{
				l = mid;
			}
		}
		else{
			long long X = r-l;
			X = xor128()%X;
			bool result = check(l+X,l+X);
			if(result){
				return 0;
			}
		}
		l-=10;
		r+=10;
		if(l<=0)l=1;
		if(r>n+1)r=n+1;
	}
	
	
	return 0;
}