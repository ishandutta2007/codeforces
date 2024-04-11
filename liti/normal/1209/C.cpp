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

const int N = 2 * 1000 * 100 + 100;

void solve() { 
	int n;
	cin >> n; 

	string s;
	cin >> s; 

	for(int d = '0'; d <= '9'; d++) { 
		int mxL = -1; 
		int mnR = -1; 
		int beg = -1;
		bool bad = false;
		for(int i = 0; i < n; i++) 
			if( s[i] < d ) { 
				if( mxL != -1 && s[mxL] > s[i] ) 
					bad = true; 
				mxL = i; 
			}


		if( bad ) continue;

		for(int i = 0; i < n; i++) 
			if( s[i] > d ) { 
				if( mnR != -1 && s[mnR] > s[i] ) 
					bad =  true;  
				if( mnR == -1 ) 
					beg = i; 
				mnR = i;
			}

		mnR = beg; 

		if( bad ) continue;

		for(int i = 0; i < n; i++) 
			if( s[i] == d && !( i >= mxL ||  i <= mnR ) )
				bad  = true;

		if( bad ) continue;

		for(int i = 0; i < n; i++) 
			if( s[i] < d ) 
				cout << 1 ;
			else if( s[i] == d && i >= mxL ) 
				cout << 1 ; 
			else if( s[i] == d && i <= mnR ) 
				cout << 2 ;
			else
				cout << 2 ;

		cout << '\n';
		return;
	}

	cout << '-' << '\n';
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); 

	int t; 
	cin >> t; 

	for(int k = 0; k < t; k++) 
		solve();
    return 0;
}