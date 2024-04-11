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

int que;	

bool go (ll a, ll b){
	if (a==0)
		return false;
	if (!go(b%a,a))
		return true;
	return 1-(b/a)%(a+1)%2;
}

int main(){
	cin >> que;
	for (int o=1; o<=que; o++){
		ll a,b; cin >> a >> b; 
		if (a>b) swap(a,b);
		cout << (go(a,b)?"First":"Second") << endl;
	}
	return 0;
}