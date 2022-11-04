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
typedef pair< int, pair<ll, bool> > node;

const int MAXK = 100+10;
const int MAXW = 400000+10;

int k;
int a [MAXK];
int dp[MAXK][MAXW];
ll n;

ll IE (const int &pos, const ll &val, const int &sgn){
	if (val==0)
		return 0;
	if (pos==k+1)
		return sgn * val;
	if (val>=MAXW)
		return IE(pos+1,val,sgn) + IE(pos+1,val/a[pos],-sgn);
	int &ret = dp[pos][val];
	if (ret!=-1)
		return sgn * ret;
	ret = IE(pos+1,val,sgn) + IE(pos+1,val/a[pos],-sgn);
	if (sgn==-1)
		ret = -ret;
	return sgn * ret;
}

int main(){
	cin >> n >> k;
	for (int i=1; i<=k; i++)
		cin >> a[i];
	sort(a+1,a+k+1,greater<int>());
	if (a[k]==1){
		cout << 0 << endl;
		return 0;
	}
	memset(dp,-1,sizeof dp);
	cout << IE(1,n,1) << endl;
	return 0;
}