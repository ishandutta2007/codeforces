#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001
unsigned long xor128() {
	static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
	unsigned long t=(x^(x<<11));
	x=y; y=z; z=w;
	return (w=(w^(w>>19))^(t^(t>>8)));
}
long long query(long long a,long long b){
	cout<<"? "<<a<<' '<<b<<endl;
	long long ret;
	cin>>ret;
	return ret;
}

void answer(long long n){
	cout<<"! "<<n<<endl;
	exit(0);
}

int main(){
	long long M = 100000000000000;
	if(query(1,M)==-1){
		long long ok = 3,ng = M;
		while(ng-ok>1LL){
			long long mid = (ok+ng)/2;
			if(query(1,mid)==-1)ng = mid;
			else ok = mid;
		}
		answer(ok);
			
	}
	else{
	
		rep(i,24){
			long long x = xor128()%M + 1;
			long long y = xor128()%M + 1;
			if(x==y){
				i--;
				continue;
			}
			long long r0 = query(x,y);

			long long r1 = query(y,x);
			if(r0!=r1){
				answer(r0+r1);
			}
		}
	}
	assert(false);
	
	return 0;
}