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
	int mod, range;

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
int k,pa,pb;
int dp[1002][1002];
int main(){
	int x,y;
	scanf("%d%d%d",&k,&x,&y);
	pa = ma.div(x, x+y);
	pb = ma.div(y, x+y);
	for(int i=k; i>=0; i--)for(int j=k-1; j>=0; j--){
		if(i == k){
			dp[i][j] = ma.add(i, ma.div(pa,pb));
		}
		else
		if(i == 0)
			dp[i][j] = dp[i+1][j];
		else
			dp[i][j] = ma.add(ma.mul(dp[i+1][j], pa), ma.mul(ma.add(j+i>=k?0:dp[i][j+i], i),pb));
	}
	printf("%d\n",dp[0][0]);
	return 0;
}