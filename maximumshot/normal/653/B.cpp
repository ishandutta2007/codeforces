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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n, q;
map< string, string > op;

string tmp;

int ans = 0;

bool check() {
	deque< char > s;
	string x;
	for(auto i : tmp) s.push_back(i);
	while((int)s.size() > 1) {
	    x.clear();
	    x.push_back(s[0]);
	    x.push_back(s[1]);
		if(!op.count(x)) return 0;
		x = op[x];
		s.pop_front();
		s.pop_front();
		s.push_front(x[0]);
	}
	return (s[0] == 'a');
}

void rec(int pos) {
	if(pos == n) {
		ans += check();
		return;
	}

	for(char c = 'a';c <= 'f';c++) {
		tmp[pos] = c;
		rec(pos + 1);
	}
}

bool solve() {
    
    cin >> n >> q;
    
    for(int i = 0;i < q;i++) {
        string x, y;
        cin >> x >> y;
        op[x] = y;
    }

	tmp.resize(n, 'a');

	rec(0);

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}