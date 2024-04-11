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

const int MAXN = 250000+10;
const int MAXT = (1<<20)+10;

int n;
int a[2*MAXN],lef[2*MAXN],mini[MAXT];
int nex[2*MAXN][20],val[2*MAXN][20];

void go (int root, int lo, int hi, int pos){
	if (pos<lo || pos>hi)
		return;
	if (lo==hi){
		mini[root] = pos;
		return;
	}
	int mid = (lo+hi)/2;
	go(root*2,lo,mid,pos);
	go(root*2+1,mid+1,hi,pos);
	if (lef[mini[root*2]] < lef[mini[root*2+1]])
		mini[root] = mini[root*2];
	else
		mini[root] = mini[root*2+1];
}
int get (int root, int lo, int hi, int st, int fn){
	if (hi<st || fn<lo)
		return 0;
	if (st<=lo && hi<=fn)
		return mini[root];
	int mid = (lo+hi)/2;
	int f1 = get(root*2,lo,mid,st,fn);
	int f2 = get(root*2+1,mid+1,hi,st,fn);
	if (lef[f1]<lef[f2])
		return f1;
	return f2;
}
int main(){		
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i]; 
		a[i+n] = a[i];
	}
	lef[0] = 2*n+1;
	for (int i=1; i<=2*n; i++){
		lef[i] = max(1,i-a[i]);
		go(1,1,2*n,i);
	}
	for (int i=0; i<20; i++){
		nex[1][i] = 1;
		val[1][i] = 1;
	}
	for (int i=2; i<=2*n; i++){
		nex[i][0] = get(1,1,2*n,lef[i],i-1);
		for (int j=1; j<20; j++)
			nex[i][j] = nex[nex[i][j-1]][j-1];
		val[i][0] = lef[i];
		for (int j=1; j<20; j++)
			val[i][j] = val[nex[i][j-1]][j-1];
	}
	ll ans = 0;
	for (int i=n+1; i<=2*n; i++){
		int cur = i;
		for (int j=19; j>=0; j--) if (i-n+1 < val[cur][j]){
			ans+= (1<<j);
			cur = nex[cur][j];
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}