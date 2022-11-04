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

const ll mod = 1000 * 1000 * 1000 + 7;

ll n; 

struct node{
	
	ll mat[2][2];

	node (){
		memset(mat,false,sizeof mat);
	}

	node operator * (const node &sec) const{
		
		node ret;

		for (int i=0; i<2; i++)
			for (int j=0; j<2; j++)
				for (int z=0; z<2; z++)
					ret.mat[i][j] = (mat[i][z] * sec.mat[z][j] + ret.mat[i][j])%mod;

		return ret;
	}
};
node BASE;

node go (ll P){
	
	if (P==0){
		node ret;
		ret.mat[0][0] = ret.mat[1][1] = 1;
		ret.mat[1][0] = ret.mat[0][1] = 0;
		return ret;
	}

	node tmp = go(P/2); 

	node ret = tmp * tmp;

	if (P & 1)
		ret = ret * BASE;

	return ret;
}

int main(){
	
	BASE.mat[0][0] = 3 , BASE.mat[0][1] = 1;
	BASE.mat[1][0] = 1 , BASE.mat[1][1] = 3;

	cin >> n;

	node x = go(n);

	cout << x.mat[0][0] << endl;

	return 0;
}