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

const int N = 1000*1000 + 10;

string a[N];
bool *ureach[N], *dreach[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 

	int n, m;
	cin >> n >> m; 

	for(int i = 0; i < n; i++) { 
		cin >> a[i]; 

		dreach[i] = new bool[m]; 
		ureach[i] = new bool[m]; 

		for(int j = 0; j < m; j++) 
			ureach[i][j] = dreach[i][j] = false;
	}

	ureach[0][0] = true; 
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) 
			if( !( i == 0 && j == 0 ) && a[i][j] == '.' ) { 
				if( i ) 
					ureach[i][j] |= ureach[i-1][j]; 
				if( j ) 
					ureach[i][j] |= ureach[i][j-1]; 
			}

	dreach[n-1][m-1] = true; 
	for(int i = n-1; i >= 0; i--) 
		for(int j = m-1; j >= 0; j--) 
			if( !( i == n-1 && j == m-1 ) && a[i][j] == '.') { 
				if( i + 1 != n ) 
					dreach[i][j] |= dreach[i+1][j]; 
				if( j + 1 != m ) 
					dreach[i][j] |= dreach[i][j+1]; 
			}


	if( !ureach[n-1][m-1] ) 
		cout << 0 << endl;
	else { 
		int ur = 0, uc = 0, dr = 0, dc = 0; 

		while( !( ur == n-1 && uc == m-1 ) ) { 
			if( ur + uc && ur == dr && uc == dc ) { 
				cout << 1 << endl;
				return 0; 
			}

			if( uc + 1 < m && ureach[ur][uc+1] && dreach[ur][uc+1] ) 
				uc++; 
			else
				ur++; 

			if( dr + 1 < n && ureach[dr+1][dc] && dreach[dr+1][dc] ) 
				dr++; 
			else
				dc++;
		}

		cout << 2 << endl;
	}

    return 0;
}