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

int n,k,query;
int dp[1<<20],fen[1<<20],ans[1<<20],cost[1<<20];
pii a [1<<20];
vector <int> age;

struct node{
	
	int r,lo,hi,ind;

	node () {}

	node (int r, int lo, int hi, int ind) : r(r) , lo(lo) , hi(hi) , ind(ind) {}

	bool operator < (const node &sec) const{
		return r>sec.r;
	}

	void print(){
		cout << "node : " << r << ' ' << lo << ' ' << hi << ' ' << ind << endl;
	}
};
vector <node> que;

void add (int root, int s, int e, int pos, int cost){

	dp[root] = max(dp[root] , cost);

	if (s==e) return;

	int mid = (s+e)/2;
	int lef = 2*root , rig= 2*root + 1;
	
	if (pos<=mid) add(lef,s,mid,pos,cost);
	else add(rig,mid+1,e,pos,cost);
}

int go (int root, int s, int e, int lo, int hi){

	if (hi<s || e<lo) 
		return 0;

	if (lo<=s && e<=hi)
		return dp[root];

	int mid = (s+e)/2;
	int lef = 2*root , rig= 2*root + 1;

	return max(go(lef,s,mid,lo,hi),go(rig,mid+1,e,lo,hi));
}

int findID (const vector <int> &Q, int x){
	
	if (Q.back()<x)
		return Q.size();

	return lower_bound(Q.begin(),Q.end(),x)-Q.begin()+1;
}

int main(){

	scanf ("%d%d", &n, &k);

	for (int i=1; i<=n; i++)   scanf("%d" , &a[i].first);
	for (int i=1; i<=n; i++) { scanf("%d" , &a[i].second); age.push_back(a[i].second); }

	scanf ("%d", &query);
	for (int i=1; i<=query; i++){
		int x,y; scanf ("%d%d" , &x, &y);
		que.push_back(node(max(a[x].first,a[y].first),max(a[x].second,a[y].second)-k,min(a[x].second,a[y].second)+k,i));
	}

	sort(a+1,a+n+1);
	sort(age.begin(),age.end()); age.resize(unique(age.begin(),age.end())-age.begin());
	sort(que.begin(),que.end());

	for (int i=1; i<=n; i++){
		int j=i;
		while (j<=n && a[i].first==a[j].first) j++;
		int poi=i;
		for (int z=i; z<j; z++){
			while (poi<j && a[poi].second<=a[z].second+k) poi++;
			int lo= findID(age,a[z].second-k)-1;
			int hi= findID(age,a[z].second+k); if (age[hi-1]>a[z].second+k) hi--; 
			cost[z] = poi-z;
		//	cout << lo << ' ' << hi << ' ' << cost[z] << endl;
			for (; hi; hi-=(hi&(-hi))) cost[z]+=fen[hi];
			for (; lo; lo-=(lo&(-lo))) cost[z]-=fen[lo];
			int cur= findID(age,a[z].second);
			for (; cur<=n; cur+=(cur&(-cur))) fen[cur]++;
		}
		i=j-1;
	}


	int poi=n;

	for (int i=0; i<(int)que.size(); i++){
		
		while (poi && a[poi].first>=que[i].r) { add(1,1,n,findID(age,a[poi].second),cost[poi]); poi--; }
		
//		que[i].print();

		int lo = findID(age,que[i].lo);
		int hi = findID(age,que[i].hi); if (age[hi-1]>que[i].hi) hi--;

		ans[que[i].ind] = go(1,1,n,lo,hi);
	}

	for (int i=1; i<=query; i++)
		printf ("%d\n", ans[i]<2 ? -1 : ans[i]);

	return 0;
}