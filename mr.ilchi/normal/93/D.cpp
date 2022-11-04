/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int mod = 1000000007;

int lo,hi;
int num[20][20];
pii par[20];

struct MAT{
	int n,m;
	vector < vector <int> > mat;
	MAT(int _n, int _m, bool _h=false){
		n = _n;
		m = _m;
		mat = vector< vector<int> > (n, vector<int>(m,0));
		if (_h)
			for (int i=0; i<n; i++)
				mat[i][i] = 1;
	}
	MAT operator * (const MAT &SEC) const{
		MAT ret = MAT(n,SEC.m);
		for (int i=0; i<n; i++)
			for (int j=0; j<SEC.m; j++)
				for (int k=0; k<m; k++)
					ret.mat[i][j] = (ret.mat[i][j] + (ll)mat[i][k] * SEC.mat[k][j]) % mod;
		return ret;
	}
	MAT POWER(int p){
		MAT ret = MAT(this->n,this->m,true);
		MAT cur = *this;
		while(p){
			if (p & 1) ret = ret*cur;
			cur = cur * cur; p= p>>1;
		}
		return ret;
	}
};

int POWER (int base, int p){
	int ret=1;
	int cur=base;
	while (p){
		if (p & 1) ret = (ll)ret*cur%mod;
		cur = (ll)cur*cur % mod; p= p>>1;
	}
	return ret;
}

int go (int hi){
	if (hi<2)
		return 4*hi;
	int code = 0;
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++) if (i/2 != j/2){
			num[i][j] = code;
			par[code] = pii(i,j);
			code++;
		}
	code++;
	MAT base = MAT(code,1);
	for (int i=0; i<code-1; i++)
		base.mat[i][0] = 1;
	base.mat[code-1][0] = code-1;
	MAT comb = MAT(code,code);
	for (int i=0; i<code-1; i++){
		for (int z=0; z<4; z++){
			int x = par[i].first;
			int y = par[i].second;
			if (y/2 == z/2)
				continue;
			if (x/2==1 && x!=z && y==1)
				continue;
			comb.mat[num[y][z]][i] = 1;
		}
	}
	for (int i=0; i<code-1; i++)
		for (int j=0; j<code-1; j++)
			comb.mat[code-1][i]+= comb.mat[j][i];
	comb.mat[code-1][code-1] = 1;
	MAT ret = comb.POWER(hi-2) * base;
	return 4+ret.mat[code-1][0];
}

int main(){
	cin >> lo >> hi; lo--;
	ll ret = 0;
	ret+= go(hi); ret+= go((hi+1)/2); ret%=mod;
	ret-= go(lo); ret-= go((lo+1)/2); ret%=mod;
	ret = ret * POWER(2,mod-2); 
	ret%=mod; ret+=mod; ret%=mod;
	cout << ret << endl;
	return 0;
}