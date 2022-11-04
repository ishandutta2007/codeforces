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
typedef long double ldb;

const int maxN = 100 * 1000 + 10;

int n,m;
int ans[maxN],dp[1<<18];
vector <int> Time;

struct range{
	int s,e,t;
	range () {}
	range (int s, int e, int t) : s(s) , e(e), t(t) {}
	bool operator < (const range & A) const{
		return s!=A.s ? s<A.s : e!=A.e ? e<A.e : t<A.t;
	}

}a[maxN],p[maxN];	

bool cmp (const int &a, const int &b){
	return p[a].s<p[b].s;
}

void add (int r, int s, int e, int pos, int cost){
	
	dp[r] = max (dp[r],cost); if (s==e) return;

	int mid = (s+e)/2;
	
	(pos<=mid) ? add (r*2,s,mid,pos,cost) : add(r*2+1,mid+1,e,pos,cost);
}

int go (int r, int s, int e, int cost, int t){

	if (dp[r]<cost || Time[e-1]<t) 
		return -1;

	if (s==e)
		return s;

	
	int ret = go(r*2,s,(s+e)/2,cost,t);

	if (ret==-1)
		ret = go(r*2+1,(s+e)/2+1,e,cost,t);

	return ret;
	
}

int main(){
	
	scanf ("%d%d" , &n, &m);
	
	map <int,int> mp;

	for (int i=1; i<=n; i++){
		scanf ("%d%d%d" , &a[i].s , &a[i].e, &a[i].t); 
		Time.push_back (a[i].t);
		mp[a[i].t] = i;
	}
	for (int i=1; i<=m; i++) 
		scanf ("%d%d%d" , &p[i].s , &p[i].e, &p[i].t);

	sort (Time.begin(),Time.end());

	sort(a+1,a+n+1);
	vector <int> que; 
	for (int i=1; i<=m; i++) 
		que.push_back (i);
	sort (que.begin(),que.end(),cmp);

	int poi=1;

	for (int i=0; i<(int)que.size(); i++){
		range v = p[que[i]];
		while (poi<=n && a[poi].s<=v.s){
			int tmp = lower_bound(Time.begin(),Time.end(),a[poi].t) - Time.begin();
			add (1,1,(int)Time.size(),tmp+1,a[poi].e);
			poi++;
		}
		ans[que[i]] = go(1,1,(int)Time.size(),p[que[i]].e,p[que[i]].t);		
	}
	
	for (int i=1; i<=m; i++){
		if (ans[i]==-1)
			printf ("%d " , ans[i]);
		else
			printf ("%d " , mp[Time[ans[i]-1]]);
	}
	printf ("\n");

	return 0;
}