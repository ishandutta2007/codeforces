//A319013
#include<bits/stdc++.h>
using namespace std;
struct modular_arithmetic{
	int mod;

	modular_arithmetic(){
		mod = 998244353;
	}
	//No specific settings.
	int add(int x,int y){return (x+=y)<mod?x:x-mod;}
	int sub(int x,int y){return (x-=y)>=0?x:x+mod;}
	int mul(int x,int y){return (int)((long long int)x*y%mod);}
	int pw(int base, int p) {
		int res = 1, mu = base%mod;
		for(;p>0;p/=2) {
			if (p&1) res = mul(res, mu);
			mu = mul(mu, mu);
		}
		return res;
	}
} ma;
int main(){
	int s = 1, b = 0, n;
	scanf("%d",&n);
	s = n;
	for(int i=1; i<n; i++){
		s=ma.mul(s,i+1);
		b=ma.add(ma.mul(b,i+1),ma.mul(i,i));
	}
	printf("%d\n",ma.sub(ma.sub(s,b),n-1));
	return 0;
}