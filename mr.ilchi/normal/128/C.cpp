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
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll mod = 1000*1000*1000 + 7;
const ll maxN = 1000 + 5;

ll n,m,k;
ll fact[maxN],dfact[maxN];

inline ll go (int x, int y){
	
	if (y>x)
		return 0;

	ll ret = fact[x] * dfact[y]; ret%=mod;
	ret*= dfact[x-y];

	return ret%mod;
}

inline ll pw (ll x , ll p){
	
	if (p==0)
		return 1;

	if (p%2==1){
		
		ll tmp = pw(x, p/2);

		tmp*=tmp; tmp%=mod; tmp*=x; tmp%=mod;

		return tmp;
	}

	ll tmp = pw(x,p/2);

	return (tmp*tmp)%mod;
}

int main(){
	
	cin >> n >> m >> k;

	fact[0] = 1;

	for (int i=1; i<maxN; i++)
		fact[i] = (fact[i-1] * (ll)i)%mod;

	for (int i=0; i<maxN; i++)
		dfact[i] = pw(fact[i],mod-2);

	cout << ((ll)go(n-1,2*k) * (ll)go(m-1,2*k))%mod << endl;

	return 0;
}