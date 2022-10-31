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

const int N = 200*1000 + 100;

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int bad = -1; 
	int cnt = 0;

	for(int i = 0; i < int(s.size()); i++) { 
		if( s[i] == '(' ) 
			cnt++; 
		else { 
			if( cnt ) 
				cnt--; 
			else if( bad == -1 ) { 
				bad = i; 
			} else { 
				cout << "No" << endl;
				return 0; 
			}
		}
	}

	if( (bad == -1 && cnt == 0) || (bad != -1 && cnt == 1) ) { 
		cout << "Yes" << endl;
	} else 
		cout << "No" << endl;

    return 0;
}