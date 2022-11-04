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

ll lo,hi;

ll go (ll hi){
	if (hi<10)
		return hi;
	vector <int> dig;
	while (hi){
		dig.push_back(hi%10);
		hi/=10;
	}
	reverse(dig.begin(),dig.end());
	ll ret = 0;
	ll now = 9;
	for (int i=1; i<(int)dig.size(); i++){
		ret+=now;
		if (i>1)
			now*=10;
	}
	for (int i=1; i<=dig[0]; i++){
		ll cur = 0;
		ll p10 = 1;
		for (int j=1; j<(int)dig.size()-1; j++){
			cur = cur*10+dig[j];
			p10*= 10;
		}
		if (i<dig[0])
			ret+=p10;
		else
			ret+= cur + (i<=dig.back());
	}	
	return ret;
}

int main(){
	cin >> lo >> hi;
	cout << go(hi) - go(lo-1) << endl;
	return 0;
}