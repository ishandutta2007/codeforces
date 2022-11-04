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
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN = 100000+10;
const int MAXT = 1<<18;

bool flag[MAXT];
int n,que;
int s[MAXN],a[MAXN],b[MAXN],cnt[MAXT];	
vector <int> first[MAXN],end[MAXN];

inline void flip (int root, int lo, int hi, int L, int R){
	if (R<lo || hi<L)
		return;
	if (L<=lo && hi<=R){
		cnt[root] = (hi-lo+1) - cnt[root];
		flag[root] = 1-flag[root];
		return;
	}
	int mid = (lo + hi) / 2;
	flip(root<<1, lo, mid, L, R);
	flip((root<<1)+1, mid+1, hi, L, R);
	cnt[root] = cnt[(root<<1)] + cnt[(root<<1)+1];
	if (flag[root])
		cnt[root] = (hi-lo+1) - cnt[root];
}

inline int get (int root, int lo, int hi, int L, int R){
	if (R<lo || hi<L)
		return 0;
	if (L<=lo && hi<=R)
		return cnt[root];
	int mid = (lo + hi) / 2;
	int ret = get((root<<1), lo, mid, L, R) + get((root<<1)+1, mid+1, hi, L, R);
	return (flag[root]) ? (min(hi,R)-max(lo,L)+1-ret) : (ret);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> que;
	for (int i=0; i<n; i++)
		cin >> s[i];
	sort(s, s+n);
	for (int i=0; i<que; i++){
		cin >> a[i] >> b[i];
		a[i] = lower_bound(s, s+n, a[i]) - s;
		b[i] = upper_bound(s, s+n, b[i]) - s - 1;
		if (b[i]<=a[i]){
			swap(a[i], a[que-1]);
			swap(b[i], b[que-1]);
			que--;
			i--;
			continue;
		}
		first[a[i]].push_back(b[i]);
		end[b[i]].push_back(a[i]);
	}
	LL ans = ((LL)n * (n-1) * (n-2)) / 6LL;
	for (int i=0; i<n; i++){
		for (int j=0; j<(int)first[i].size(); j++)
			flip(1, 0, n-1, i, first[i][j]);
		int deg = i-get(1, 0, n-1, 0, i-1) + get(1, 0, n-1, i+1, n-1);
		ans-= ((LL)deg * (deg-1)) / 2;
		for (int j=0; j<(int)end[i].size(); j++)
			flip(1, 0, n-1, end[i][j], i);
	}
	cout << ans << endl;
	return 0;
}