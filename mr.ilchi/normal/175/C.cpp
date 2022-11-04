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

int n,t;
pll a[200];
ll p[200];

int main(){

	cin >> n;

	for (int i=1; i<=n; i++)
		cin >> a[i].second >> a[i].first;

	cin >> t;
	
	for (int i=1; i<=t; i++)
		cin >> p[i];

	for (int i=t; i>1; i--){
		p[i] = p[i] - p[i-1];
	}

	p[t+1] = (1ll<<60);

	ll ans = 0;

	int poi=1;

	sort(a+1,a+n+1);

	for (int i=1; i<=n; i++){
		while (a[i].second>0ll){
			ll rem = min(a[i].second, p[poi]);
			p[poi]-=rem;
			a[i].second-=rem;
			ans+= rem * (ll)poi * a[i].first;
			if (p[poi]==0)
				poi++;
		}
	}

	cout << ans << endl;

	return 0;
}