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

const int MAXL = 10100;
char buffer[MAXL];

void read(string & s) {
	scanf("%s", &buffer);
	s = buffer;
}

bool solve() {

	int n;
	cin >> n;

	string s;
	read(s);

	int m;
	cin >> m;

	vec< string > w(m);
	for(int i = 0;i < m;i++) read(w[i]);

	vec< int > add(26, -1), id;
	vec< vec< int > > bor;
	bor.push_back(add);
	id.push_back(-1);

	for(int i = 0;i < m;i++) {
		int v = 0;
		for(int c, j = 0;j < (int)w[i].size();j++) {
			c = ('a' <= w[i][j] && w[i][j] <= 'z'?w[i][j] - 'a' : w[i][j] - 'A');
			if(bor[v][c] == -1) {
				bor.push_back(add);
				id.push_back(-1);
				bor[v][c] = (int)bor.size() - 1;
			}
			v = bor[v][c];
		}
		id[v] = i;
	}

	vec< char > dp(n);
	vec< int > from(n, -1);

	for(int i = 0;i < n;i++) {
		for(int c, v = 0, j = i;j >= 0;j--) {
			c = s[j] - 'a';
			if(bor[v][c] == -1) break;
			v = bor[v][c];
			if(id[v] == -1) continue;
			if(j > 0) {
				if(dp[j - 1]) dp[i] = 1, from[i] = id[v];
			}else {
				dp[i] = 1, from[i] = id[v];
			}
		}
	}

	vec< int > way;

	for(int i = n - 1;i >= 0;) {
		way.push_back(from[i]);
		i -= (int)w[from[i]].size();
	}

	reverse(ALL(way));

	for(int i = 0;i < (int)way.size();i++) {
		for(int j = 0;j < (int)w[way[i]].size();j++) {
			printf("%c", w[way[i]][j]);
		}
		printf(" ");
	}

	printf("\n");

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}