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

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

char buff[100];

pair< string, string > read() {
	scanf("%s", &buff);
	int n = strlen(buff);
	int i = 7;
	while(i < n && buff[i] != '/') i++;
	i--;
	string a, b;
	a = b = "";
	for(int j = 0;j <= i;j++) a += buff[j];
	for(int j = i + 1;j < n;j++) b += buff[j];
	return mp(a, b);
}

bool solve() {

	int n;
	scanf("%d", &n);

	vec< pair< string, string > > a(n), b;

	for(int i = 0;i < n;i++) {
		a[i] = read();
	}

	sort(ALL(a));
	a.resize(unique(ALL(a)) - a.begin());

	for(int i = 0;i < (int)a.size();i++) {
		int j = i;
		string t = "";
		while(j < (int)a.size() && a[i].first == a[j].first) {
			t += a[j++].second + "#";
		}
		b.push_back(mp(t, a[i].first));
		i = j - 1;
	}

	sort(ALL(b));
	
	vec< vec< string > > ans;
	vec< string > way;

	for(int i = 0;i < (int)b.size();i++) {
		int j = i;
		way.clear();
		while(j < (int)b.size() && b[i].first == b[j].first) {
			way.push_back(b[j++].second);
		}
		if((int)way.size() > 1) ans.push_back(way);
		i = j - 1;
	}

	printf("%d\n", (int)ans.size());

	for(auto i : ans) {
		for(auto j : i) {
			for(auto k : j) printf("%c", k);
			printf(" ");
		}
		printf("\n");
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}