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

const int maxN = 100 * 1000 + 10;
const double eps = 1e-9;

int n,k,h;
pair < pii , int > a[maxN];

int main(){

	ios_base::sync_with_stdio(false);

	cin >> n >> k >> h;

	for (int i=1; i<=n; i++) cin >> a[i].first.first;
	for (int i=1; i<=n; i++) cin >> a[i].first.second;
	for (int i=1; i<=n; i++) a[i].second = i;

	sort (a+1,a+n+1);

	vector <int> ans;

	double lo=0.0,hi=2e9;

	for (int rep=1; rep<=100; rep++){
		
		double mid = (lo + hi) / 2.0;

		vector <int> Q;

		int now = 1;

		for (int i=1; i<=n && now<=k; i++){
			double Time = (now * h) / (double)a[i].first.second;
			if (Time <= mid + eps){
				Q.push_back (a[i].second);
				now ++;
			}
		}

		if (now>k){
			hi = mid;
			ans = Q;
		}
		else
			lo = mid;
	}

	for (int i=0; i<(int)ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;

	return 0;
}