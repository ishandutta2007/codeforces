#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define i64 long long int

const int B = 32768;
i64 mulmod(i64 X,i64 Y,i64 mod){
	if (Y == 0)return 0;
	return (mulmod(X, Y / B, mod) * B + X * (Y % B)) % mod;
}
bool pw(i64 X,i64 Y,i64 mod){
	i64 R = 1, W = X;
	while(1){
		if(Y&1)R = mulmod(R,W,mod);
		if(Y>>=1)W = mulmod(W,W,mod);else
			break;
	}
	return R == 1;
}

i64 N, X;
vector<pair<i64, int> > fac;
vector<vector<i64> > e;

int L;
i64 res;

i64 gcd(i64 X, i64 Y){
	return Y?gcd(Y,X%Y):X;
}
i64 LCM(i64 X, i64 Y){
	return X/gcd(X, Y)*Y;
}
void dfs(int i,i64 cur,i64 lcm){
	if(i == L){
		res += cur / lcm;
		return;
	}
	dfs(i+1, cur, lcm);
	i64 P = fac[i].first;
	cur *= (P-1);
	dfs(i+1, cur, LCM(lcm, e[i][1]));
	for(int j=2; j <= fac[i].second; j++){
		cur *= P;
		dfs(i+1, cur, LCM(lcm, e[i][j]));
	}
}
int main() {
	cin >> N >> X;
	for (i64 i = 2; i * i <= N; i++)if (N % i == 0) {
		int c = 0;
		while (N % i == 0) {
			N /= i;
			c++;
		}
		fac.push_back(make_pair(i, c));
	}
	if (N > 1)fac.push_back(make_pair(N, 1));

	L = fac.size();
	e.resize(L);
	for (int i = 0; i < L; i++) {
		i64 P = fac[i].first, E = fac[i].second;
		e[i].resize(E + 1);

		i64 X2 = X % P, T = 1;
		bool ff = false;
		for(; T * T <= P - 1; T ++)if((P-1)%T == 0)
			if(pw(X2, T, P)){
				e[i][1] = T;
				ff = true;
				break;
			}
		if(!ff){
			for(; T >= 1; T --)if((P-1)%T==0){
				if(pw(X2, (P-1)/T, P)){
					e[i][1] = (P-1)/T;
					ff = true;
					break;
				}
			}
		}
		i64 PP = P;
		for (int j = 2; j <= E; j++) {
			PP *= P;
			if(pw(X % PP, e[i][j-1], PP))
				e[i][j] = e[i][j-1];
			else
				e[i][j] = e[i][j-1] * P;
		}
	}

	dfs(0, 1, 1);
	cout << res << endl;
	return 0;
}