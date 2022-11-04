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

const int MAXN = 1000000+10;
const int MAXT = (1<<21)+10;
const int INF = 1000000001;

int n,m;
int a[MAXN],k[MAXN];
pii mini[MAXT];
ll val[MAXN],inc[MAXN],ans[MAXN];

pii getMin(int root, int lo, int hi, int beg, int fin){
	if (fin<lo || hi<beg)
		return pii(INF,-1);
	if (beg<=lo && hi<=fin)
		return mini[root];
	int mid = (lo+hi)/2;
	return min(getMin(root<<1,lo,mid,beg,fin),getMin((root<<1)+1,mid+1,hi,beg,fin));
}

void addMin(int root, int lo, int hi, int pos, int cost){
	if (lo==hi){
		mini[root]=pii(cost,lo);
		return;
	}
	int mid=(lo+hi)/2;
	(pos<=mid) ? (addMin(root<<1,lo,mid,pos,cost)) : (addMin((root<<1)+1,mid+1,hi,pos,cost));
	mini[root]=min(mini[root<<1],mini[(root<<1)+1]);
}

void addSum(int beg, int fin, ll cost, ll d){
	if (fin<beg)
		return;
	val[beg]+= cost; val[fin+1]-=(fin-beg)*d+cost;
	inc[beg+1]+= d; inc[fin+1]-= d;
}

void go (int lo, int hi){
	if (lo>hi)
		return;
	int pos = getMin(1,1,n,lo,hi).second;
	go(lo,pos-1);
	go(pos+1,hi);
	int lef=(pos-lo+1);
	int rig=(hi-pos+1);
	ll c=a[pos];
	if (lef<=rig){
		addSum(1,lef-1,c,c);
		addSum(lef,rig,c*lef,0);
		addSum(rig+1,hi-lo+1,c*(lef-1),-c);
	}
	else{
		addSum(1,rig-1,c,c);
		addSum(rig,lef,c*rig,0);
		addSum(lef+1,hi-lo+1,c*(rig-1),-c);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n; for (int i=1; i<=n; i++) cin >> a[i];;
	cin >> m; for (int i=1; i<=m; i++) cin >> k[i];
	for (int i=1; i<=n; i++)
		addMin(1,1,n,i,a[i]);
	go(1,n);
	ll v=0,d=0;
	for (int i=1; i<=n; i++){
		v+= val[i];
		d+= inc[i]; 
		v+= d;
		ans[i] = v;
	}
	cout << fixed << setprecision(10);
	for (int i=1; i<=m; i++)
		cout << (ldb)ans[k[i]]/(n-k[i]+1.0) << '\n';
	return 0;
}