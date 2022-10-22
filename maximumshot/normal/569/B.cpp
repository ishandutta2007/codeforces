#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <time.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve() 
{
	int n;

	cin >> n;

	set< int > s;
	for(int i = 1;i <= n;i++) s.insert(i);

	vec< int > a(n + 1), c(n + 1, 0);
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(a[i] <= n) s.erase(a[i]), c[a[i]]++;
		else a[i] = 0;
	}
	for(int i = 1;i <= n;i++) {
		if(s.empty() || c[a[i]] == 1) cout << a[i] << ' ';
		else {
			c[a[i]]--;
			cout << *(s.begin()) << ' ';
			s.erase(s.begin());
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}