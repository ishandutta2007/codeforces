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

int n,m,k;
int l[1<<20], r[1<<20], d[1<<20],cnt[1<<20];
LL a[1<<20],ans[1<<20];

int main(){
	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<m; i++){
		cin >> l[i] >> r[i] >> d[i];
		l[i]--; r[i]--;
	}
	for (int i=0; i<k; i++){
		int lo,hi; cin >> lo >> hi;
		cnt[lo-1]++;
		cnt[hi]--;
	}
	for (int i=0; i<m; i++){
		if (i>0) cnt[i]+=cnt[i-1];
		ans[l[i]]+= (LL)d[i] * cnt[i];
		ans[r[i]+1]-= (LL)d[i] * cnt[i];
	}
	for (int i=1; i<n; i++)
		ans[i]+= ans[i-1];
	for (int i=0; i<n; i++)
		cout << ans[i] + a[i] << ' ';
	cout << endl;
	return 0;
}