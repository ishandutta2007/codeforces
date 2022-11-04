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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;

const int maxN= 1000 * 1000 + 10;
const ll key1 = 701;
const ll key2 = 1000 * 1000 * 1000  + 7;

int n,e;
vector <int> adj[maxN];

ll go (vector <pll> &Q){
	
	ll ret = 0;

	for (int i=0; i<(int)Q.size(); i++){
		int j=i;
		while (j<(int)Q.size() && Q[i]==Q[j])
			j++;
		ll Size = j-i; i=j-1;
		ret+= Size * (Size-1) / 2ll;
	}

	return ret;
}

int main(){

	scanf ("%d%d" , &n, &e);
	for (int i=1; i<=e; i++){
		int a,b; scanf ("%d%d" , &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector <pll> Q,P;
	for (int i=1; i<=n; i++){
		ll h1=0,h2=0;
		sort (adj[i].begin(),adj[i].end());
		for (int j=0; j<adj[i].size(); j++){
			h1 = h1 * key1 + adj[i][j];
			h2 = h2 * key2 + adj[i][j];
		}
		Q.push_back (pll(h1,h2));
		adj[i].push_back(i);
		sort (adj[i].begin(),adj[i].end());
		h1 = h2 = 0;
		for (int j=0; j<adj[i].size(); j++){
			h1 = h1 * key1 + adj[i][j];
			h2 = h2 * key2 + adj[i][j];
		}
		P.push_back (pii(h1,h2));
	}

	sort (Q.begin(),Q.end());
	sort (P.begin(),P.end());

	ll ans = 0;

	ans+= go(Q);
	ans+= go(P);

	printf ("%I64d\n" , ans);
	
	return 0;
}