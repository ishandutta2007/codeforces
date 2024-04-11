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
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 100*1000 +10;
const int maxM = 100*100 + 10;
const int base = 100;

int n,m;
int a[maxN],h[maxN],l[maxN],r[maxN];
pii mush[maxM];
double dp[maxM],gr[maxM];

inline int root (int x){
	
	return (x-1)/base + 1;
}

inline void update (int x, int y, double f){
	
	x++; y++;

	if (x>m || y>m || x>y)
		return;

	int p1 = root(x);
	int p2 = root(y);

	if (p1==p2){
		while (x<=y) { dp[x]*=f; x++; }
		return;
	}

	while (root(x)==p1) { dp[x]*=f; x++; } p1++;

	while (p1<p2) { gr[p1]*=f; p1++; };

	while (root(y)==p2 && y>0) { dp[y]*=f; y--; } 
}

int main(){

	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i=1; i<=n; i++)
		cin >> a[i] >> h[i] >> l[i] >> r[i];
	for (int i=1; i<=m; i++)
		cin >> mush[i].first >> mush[i].second;

	sort (mush+1,mush+m+1);

	vector <int> Q;

	for (int i=1; i<=m; i++)
		Q.push_back (mush[i].first);

	for (int i=0; i<maxM; i++)
		dp[i] = gr[i] = 1.0;

	for (int i=1; i<=n; i++){
		
		int lx = lower_bound(Q.begin(),Q.end(),a[i]-h[i]) - Q.begin();
		int p  = lower_bound(Q.begin(),Q.end(),a[i]) - Q.begin();
		update(lx,p-1,1.0-(double)l[i]/100.0);
		int rx = upper_bound(Q.begin(),Q.end(),a[i]+h[i]) - Q.begin();
		int pp = upper_bound(Q.begin(),Q.end(),a[i]) - Q.begin();
		update(pp,rx-1,1.0-(double)r[i]/100.0);
	}

	for (int i=1; i<=m; i++)
		dp[i]*=gr[root(i)];

	double ans = 0;

	for (int i=1; i<=m; i++)
		ans+= dp[i] * mush[i].second;

	cout << fixed << setprecision (9) << ans << endl;

	return 0;
}