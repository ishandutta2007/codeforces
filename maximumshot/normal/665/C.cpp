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

	int n = (int)s.size();

	for(int i = 0;i < n;i++) {
		int j = i;
		while(j < n && s[i] == s[j]) j++; 
		j--;
		// 
		for(int q = i + 1;q <= j;q += 2) {
			for(char c = 'a';c <= 'c';c++) {
				if(q > 0 && s[q - 1] == c) continue;
				if(q + 1 < n && s[q + 1] == c) continue;
				s[q] = c;
				break;
			}
		}
		i = j;
	}

	cout << s << '\n';

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}