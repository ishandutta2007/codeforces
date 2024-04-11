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

const int N = 200 * 1000 + 100;

int cnt[N]; 

int a[N]; 
int r[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); 

	int n, q;
	cin >> n >> q; 

	for(int i = 0; i < n; i++) {
		cin >> a[i]; 
		cnt[a[i]]++; 
		r[a[i]] = i; 
	}


	int ans = n; 

	for(int i = 0, j; i < n; i = j + 1) { 
		j = r[a[i]]; 
		int mx = -1; 
		for(int k = i; k <= j; k++) { 
			j = max(j, r[a[k]]); 
			mx = max(mx, cnt[a[k]]); 
		}

		ans -= mx; 
	}

	cout << ans << endl;

    return 0;
}