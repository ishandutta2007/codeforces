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
int a[N];

int main() {
	int n;
	cin >> n; 

	for(int i =0; i < n; i++) 
		cin >> a[i]; 

	set<int> ans;
	for(int i = 0; i < n; i++) {
		bool good = true;
		for(int j = 0; j < n; j++) 
			if( a[j] < a[i] && a[i] % a[j] == 0 ) 
				good = false;
		if( good ) ans.insert( a[i] ); 
	}

	cout << ans.size() << endl;
}