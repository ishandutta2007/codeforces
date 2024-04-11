#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

const int N = 15;

bool solve() {

	char mirror[N] = {'A', 'H', 'I', 'M', 'O', 'o', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y'};

	vec< char > can(300);

	for(int i = 0;i < N;i++) can[mirror[i]] = 1;

	string s;
	cin >> s;

	int n = (int)s.size();

	for(int i = 0;i < n / 2 + n % 2;i++) {
		if(s[i] == s[n - 1 - i]) {
			if(!can[s[i]]) {
				cout << "NIE\n";
				return true;
			}
		}else {
			if(s[i] == 'b' && s[n - 1 - i] == 'd' || 
				s[i] == 'd' && s[n - 1 - i] == 'b' || 
				s[i] == 'p' && s[n - 1 - i] == 'q' ||
				s[i] == 'q' && s[n - 1 - i] == 'p') {}
			else {
				cout << "NIE\n";
				return true;
			}
		}
	}

	cout << "TAK\n";
	
	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}