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

const int MAXN = 5000+10;

bool col[MAXN];
int n,comp;
int x[MAXN],y[MAXN],par[MAXN],sz[MAXN];
vector <int> Q[MAXN],store[2*MAXN];

bool Union (int A, int B){
	int a = par[A];
	int b = par[B];
	if (a==b)
		return col[A]!=col[B];
	if (sz[a]<sz[b])
		swap(a,b);
	bool diff = (col[A]==col[B]);
	comp--;
	Q[a].resize(sz[a]+sz[b]);
	for (int i=0; i<(int)Q[b].size(); i++){
		Q[a][sz[a]+i] = Q[b][i];
		par[Q[b][i]] = a;
		col[Q[b][i]]^= diff;
	}
	sz[a]+=sz[b]; sz[b]=0;
	return true;
}

int main(){
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> x[i] >> y[i];
	for (int i=1; i<=n; i++){
		for (int j=i+1; j<=n; j++){
			int d = labs(x[i]-x[j]) + labs(y[i]-y[j]);
			store[d].push_back(i*(n+1)+j);
		}
	}
	for (int i=1; i<=n; i++){
		sz [i]=1; 
		par[i]=i;
		Q[i].push_back(i);
	}
	comp = n;
	int res=-1,cnt=-1;
	for (int i=10001; i>0; i--){
		bool bad = false;
		for (int j=0; j<(int)store[i].size(); j++) if (!Union(store[i][j]%(n+1), store[i][j]/(n+1))){
			bad = true;
			break;
		}
		if (bad)	
			break;
		res = i-1;
		cnt = comp;
	}
	int resc = 1;
	for (int i=1; i<=cnt; i++)
		resc = resc * 2 % 1000000007;
	cout << res << endl << resc << endl;
	return 0;
}