#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool is_open(char x) {
	return (x == '<' || x == '{' || x == '[' || x == '(' || x == 'o');
}

bool equal(char open, char close) {
	if(open == 'o') return 1;
	if(open == '[' && close == ']') return 1;
	if(open == '<' && close == '>') return 1;
	if(open == '{' && close == '}') return 1;
	if(open == '(' && close == ')') return 1;
	return 0;
}

bool solve() {

	string s;
	cin >> s;

	int d = 0;

	for(auto i : s) {
		if(is_open(i)) d++;
		else d--;
		if(d < 0) {
			cout << "Impossible\n";
			return true;
		}
	}

	if(d > 0) {
		cout << "Impossible\n";
		return true;
	}

	int ans = 0;
	vec< char > a;

	for(char i : s) {
		if(is_open(i)) a.push_back(i);
		else {
			char x = a.back();
			a.pop_back();
			if(!equal(x, i)) ans++;
		}	
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}