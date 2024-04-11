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

const int m[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool solve() {
	
	int x;
	string s;

	cin >> x >> s >> s;

	x--;

	int ans = 0;

	if(s== "week") {
		for(int day_of_month = 0, day_of_week = 4, month = 0;;) {
			if(day_of_week == x) ans++;
			day_of_week = (day_of_week + 1) % 7;
			if(day_of_month + 1 < m[month]) day_of_month++;
			else {
				if(month == 11) break;
				else month++, day_of_month = 0;
			}
		}
	}else {
		for(int day_of_month = 0, day_of_week = 4, month = 0;;) {
			if(day_of_month == x) ans++;
			day_of_week = (day_of_week + 1) % 7;
			if(day_of_month + 1 < m[month]) day_of_month++;
			else {
				if(month == 11) break;
				else month++, day_of_month = 0;
			}
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