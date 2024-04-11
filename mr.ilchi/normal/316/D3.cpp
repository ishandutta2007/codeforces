/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN = 1000000+10;
const int mod = 1000000007;

int n,c1,c2;
int f[MAXN],df[MAXN];

inline int POWER (int base, int p){
	int ret = 1;
	int cur = base;
	while (p){
		if (p & 1)
			ret = (LL)ret * cur % mod;
		cur = (LL)cur * cur % mod;
		p>>=1;
	}
	return ret;
}

inline int getC (int n, int k){
	return (LL)f[n] * df[k] % mod * df[n-k] % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		c1+= temp==1;
		c2+= temp==2;
	}
	f[0]=df[0]=1;
	for (int i=1; i<MAXN; i++){
		f [i] = (LL)f[i-1] * i % mod;
		df[i] = POWER(f[i], mod-2);
	}
	int ret = 0;
	for (int i=c1%2; i<=c1; i+=2){
		int temp = (LL)getC(c1,i) * f[c1-i] % mod * POWER(df[2],(c1-i)/2) % mod * df[(c1-i)/2] % mod;
		ret = (ret + (LL)temp * f[n] % mod * df[c1]) % mod;
	}
	cout << ret << endl;
	return 0;
}