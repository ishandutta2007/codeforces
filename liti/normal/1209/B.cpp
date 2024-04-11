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

const int N = 100 + 10;

int a[N], b[N]; 

bool val[N];

int main() {
	int n;
	cin >> n; 

	string s; 
	cin >> s; 

	int ans = 0; 
	for(int i = 0; i < n; i++)  { 
		val[i] = (s[i] == '1'); 
		if( val[i] ) ans++; 
	}

	for(int i = 0; i < n; i++) 
		cin >> a[i] >> b[i]; 

	const int K = 3000 * 100 ; 
	for(int t = 1; t < K; t++) { 
		int tmp = 0; 
		for(int i = 0; i < n; i++) { 
			if( t >= b[i] && (t - b[i]) % a[i] == 0 ) 
				val[i] ^= 1;
			if( val[i] ) tmp++; 
		}
		ans = max(ans, tmp); 
	}

	cout << ans << endl;


    return 0;
}