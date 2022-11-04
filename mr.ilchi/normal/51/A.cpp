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

int n,ans;
set <string> SET;

int main(){
	cin >> n;
	for (int i=1; i<=n; i++){
		string s1,s2; cin >> s1 >> s2;
		string s; 
		if (i!=n)
			cin >> s;
		swap(s2[0],s2[1]);
		s = s1 + s2;
		if (SET.find(s)!=SET.end())
			continue;
		s = s + s;
		SET.insert(s.substr(0,4));
		SET.insert(s.substr(1,4));
		SET.insert(s.substr(2,4));
		SET.insert(s.substr(3,4));
		ans++;
	}
	cout << ans << endl;
	return 0;
}