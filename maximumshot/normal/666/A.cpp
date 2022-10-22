#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

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

bool solve() {
	
	string s;
	cin >> s;

	set< string > ans;
 
	int n = (int)s.size();

	vec< char > can2(n + 1);
	vec< char > can3(n + 1);

	can2[n] = 1;
	can3[n] = 1;

	for(int i = n - 2;i >= 5;i--) {
		
		if(can3[i + 2] || can2[i + 2] && s.substr(i, 2) != s.substr(i + 2, 2)) can2[i] = 1, ans.insert(s.substr(i, 2));
		if(i + 2 < n) {
			if(can2[i + 3] || can3[i + 3] && s.substr(i, 3) != s.substr(i + 3, 3)) 
				can3[i] = 1, ans.insert(s.substr(i, 3));
		}
	}

	cout << (int)ans.size() << '\n';
	for(auto i : ans) cout << i << '\n';

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}