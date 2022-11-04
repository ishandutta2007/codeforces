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

int n,m,x,y;
int a[maxN],b[maxN];

int main(){

	cin >> n >> m >> x >> y; 
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int j=1; j<=m; j++) cin >> b[j];

	vector <pii> ans;
	int poi = 1;
	for (int i=1; i<=n; i++){
		while (poi<=m && b[poi]<a[i]-x) poi++;
		if (poi<=m && a[i]-x<=b[poi] && b[poi]<=a[i]+y){
			ans.push_back (pii(i,poi));
			poi++;
		}
	}

	cout << ans.size() << endl;
	for (int i=0; i<(int)ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;
	
	return 0;
}