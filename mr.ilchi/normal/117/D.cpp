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

ll n,que,mod,lo,hi,u,v;

ll go (ll beg, ll fin, ll start, ll d){
	if (fin<lo || hi<beg)
		return 0;
	if (lo<=beg && fin<=hi){
		ll end = start + d * (fin-beg);
		if (start<u) start = start + (u-start+d-1)/d*d;
		if (end>v) end = end - (end-v+d-1)/d*d;
		if (start>end)
			return 0;
		ll beg = start + end;
		ll len = (end-start)/d+1;
		if (beg%2==0) beg/=2; else len/=2;
		return (beg%mod) * (len%mod) % mod;
	}
	ll mid = (beg+fin)/2;
	return (go(beg,mid,start,d<<1) + go(mid+1,fin,start+d,d<<1))%mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> que >> mod;
	for (int i=1; i<=que; i++){
		cin >> lo >> hi >> u >> v;
		cout << go(1,n,1,1) << endl;
	}
	return 0;
}