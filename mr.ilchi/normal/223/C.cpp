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

const int MAXN= 2000+10;
const int mod = 1000000007;

int n,k;
int C[MAXN],a[MAXN],fact[MAXN],dfact[MAXN];

int POWER (int base, int p){
	int ret=1;
	int cur=base;
	while (p){
		if (p & 1) ret = (ll)ret * cur % mod;
		p>>=1;
		cur = (ll)cur * cur % mod;
	}
	return ret;
}
/*
int getC (int n, int k){
	if (n<k)
		return 0;
	if (k==0 || n==k)
		return 1;
	int ret = 0;
	for (int i=n; i>n-k; i++)
		ret = (ll)ret * i % mod;
	return (ll)ret * dfact[k] % mod;
}
*/
int main(){
	fact[0]=1;
	for (int i=1; i<MAXN; i++)
		fact[i] = (ll)fact[i-1] * i % mod;
	dfact[0]=1;
	for (int i=1; i<MAXN; i++)
		dfact[i] = POWER(fact[i],mod-2);
	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	if (k==0){
		for (int i=0; i<n;i++)
			cout << a[i] << ' ';
		cout << endl;
		return 0;
	}
	for (int i=0; i<n; i++){
		int ans = 0;
		int cur = 1;
		for (int j=i; j>=0; j--){
			ans = (ans + ((ll)cur * dfact[i-j]) %mod * a[j]) % mod;
			cur = (ll)cur * (k+i-j) % mod;
		}
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}