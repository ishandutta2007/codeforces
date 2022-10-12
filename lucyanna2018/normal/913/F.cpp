/*#### bits/stdc++.h */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<deque>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
/*####*/

/*#### modular_arithmetic */
class modular_arithmetic{
public:
	int mod;

	modular_arithmetic(){
		mod = 1000000007;
	}
	//No specific settings.
	void set_mod(int _mod){mod = _mod;}
	int add(int x,int y){return (x+y)%mod;}
	int sub(int x,int y){return (x-y+mod)%mod;}
	int mul(int x,int y){return (int)((long long int)x*y%mod);}
	int pw(int x,int y){
		int r = 1;
		while(1){
			if(y&1)r=mul(r,x);
			if(y>>=1)x=mul(x,x);else
				break;
		}
		return r;
	}
	//mod must be a prime.
	int inv(int x){
		return pw(x, mod-2);
	}
	int div(int x,int y){
		return mul(x, inv(y));
	}
};
/*####*/
modular_arithmetic ma;

#define ran 2022
int n;
int dp3[ran][ran],pp[ran];
int dp[ran], dp2[ran], dd[ran][ran];
int main(){
	int a, b;
	ma.set_mod(998244353);
	scanf("%d%d%d",&n,&a,&b);

	int p = ma.div(a, b);
	int p1 = ma.sub(1, p);
	int pp1 = ma.div(p, p1);
	int ppp = ma.div(ma.sub(b,a), a);
	pp[0] = 1;for(int i=1; i<=n; i++)pp[i] = ma.mul(pp[i-1], ppp);

	for(int i=0; i<=n; i++)
		for(int j=0; j<=i; j++)
			if(j==0)dp3[i][j] = 1;else
			dp3[i][j] = ma.add(dp3[i-1][j], ma.mul(dp3[i-1][j-1], pp[i]));

	dp[1] = 1;
	for(int i=2; i<=n; i++){
		dp[i] = 1;
		for(int j=1; j<i; j++){
			dd[i][j] = ma.mul(ma.mul(dp[j], dp3[i][j]), ma.mul(ma.pw(p, j*(i-j)),ma.pw(pp1, (1+j)*j/2)));
			dp[i] = ma.sub(dp[i], dd[i][j]);
		}
	}

	dp2[1] = 0;
	for(int i=2; i<=n; i++){
		dp2[i] = ma.mul(dp[i], i*(i-1)/2);
		for(int j=1; j<i; j++){
			dp2[i] = ma.add(dp2[i], ma.mul(dd[i][j], ma.add(ma.add(j*(j-1)/2+j*(i-j),dp2[j]),dp2[i-j])));
		}
		dp2[i] = ma.div(dp2[i], ma.sub(1, dp[i]));
	}
	printf("%d\n",dp2[n]);
	return 0;
}