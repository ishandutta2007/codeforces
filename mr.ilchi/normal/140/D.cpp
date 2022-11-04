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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;

int n;
int a[123];

int main(){
	
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int ans=0,pen=0,now=0;

	sort (a+1 , a+n+1);

	for (int i=1; i<=n; i++){
		now+=a[i];
		if (now>710)
			break;
		ans++;
		pen+= max(0,now-350);
	}
	cout << ans << ' ' << pen << endl;
	return 0;
}