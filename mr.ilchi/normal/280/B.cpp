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

int n;
int a[MAXN];

inline int go (){
	int ret = 0;
	stack <int> st;
	for (int i=0; i<n; i++){
		while (!st.empty() && st.top() < a[i])
			st.pop();
		if (!st.empty())
			ret = max(ret, a[i] ^ st.top());
		st.push(a[i]);
	}
	return ret;
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++) 
		cin >> a[i];
	int ans = go(); reverse(a, a+n);
	ans = max(ans, go());
	cout << ans << endl;
	return 0;
}