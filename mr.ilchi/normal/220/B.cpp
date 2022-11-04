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
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 100000+10;

int n,que;
int a[MAXN],cnt[MAXN],lo[MAXN],hi[MAXN],ans[MAXN];
map <int,int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> que;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		if (mp.find(a[i])==mp.end())
			mp[a[i]]=0;
		mp[a[i]]++;
	}
	vector <int> store;
	for (map<int,int> :: iterator it = mp.begin(); it!=mp.end(); it++) if ((it->second)>=(it->first))
		store.push_back(it->first);
	for (int i=1; i<=que; i++)
		cin >> lo[i] >> hi[i];
	for (int rep=0; rep<(int)store.size(); rep++){
		cnt[0]=0;
		for (int i=1; i<=n; i++) 
			cnt[i] = cnt[i-1] + (a[i]==store[rep]);
		for (int i=1; i<=que; i++) if ((cnt[hi[i]]-cnt[lo[i]-1])==store[rep])
			ans[i]++;
	}
	for (int i=1; i<=que; i++)
		cout << ans[i] << endl;
	return 0;
}