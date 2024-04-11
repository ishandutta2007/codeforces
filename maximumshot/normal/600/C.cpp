#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

bool solve() {
	
	string s;

	cin >> s;

	int n = (int)s.size();

	vec< int > c(26);

	for(auto i : s) c[i - 'a']++;

	int cnt = 0;

	for(int i = 0;i < 26;i++) cnt += c[i] % 2;

	for(int i = 25;i >= 0;i--) {
		if(c[i] % 2 == 0) continue;
		if(cnt <= 1) break;
		for(int j = 0;j < i;j++) {
			if(c[j] % 2) {
				c[j]++;
				c[i]--;
				cnt -= 2;
				break;
			}
		}
	}

	int now = 0;

	for(int i = 0;i < 26;i++) {
		if(c[i] % 2) s[n / 2] = char(i + 'a'), c[i]--;
		int tmp = c[i] / 2;
		// [now .. now + tmp - 1]
		for(int j = now;j < now + tmp;j++) {
			s[j] = s[n - j - 1] = char(i + 'a');
		}
		now += tmp;
	}

	cout << s << '\n';

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}