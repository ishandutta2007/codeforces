//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 100 * 1000 + 10;

pii a[N];

int main() {
	int n;
	cin >> n; 

	for(int i = 0; i < n; i++) { 
		cin >> a[i].F;
		a[i].S = i; 
	}

	sort(a, a + n, greater<pii>()); 

	vector<int> chain; 
	for(int i = 0; i < n; i++) 
		chain.pb(a[i].S*2); 

	for(int i = 0; i < n; i++) { 
		assert( i + a[i].F <= chain.size() ); 
		if( i + a[i].F == chain.size() ) 
			chain.pb( a[i].S * 2 + 1 ); 
		else
			cout << chain[i+a[i].F-1]+1 << ' ' << a[i].S*2 + 2 << '\n';
	}

	for(int i = 0; i + 1 < int(chain.size()); i++) 
		cout << chain[i]+1 << " " << chain[i+1]+1 << '\n';

    return 0;
}