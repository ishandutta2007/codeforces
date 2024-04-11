#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;

int n;
char s[2100000];
char s1[1100000];
char s2[1100000];
int z[2100000];

int main() {
	scanf("%d ", &n);
	--n;
	scanf(" %s", s1);
	scanf(" %s", s2);
	reverse(s1, s1 + n);
	for (int i = 0; i < n; ++i) {
		if (s1[i] == 'N')
			s[i] = 'S';
		else if (s1[i] == 'S')
			s[i] = 'N';
		else if (s1[i] == 'E')
			s[i] = 'W';
		else if (s1[i] == 'W')
			s[i] = 'E';
	}
	s[n] = '#';
	for (int i = 0; i < n; ++i) {
		s[i + n + 1] = s2[i];
	}
	int l = 0, r = 0;
	z[0] = 0;
	for (int i = 1; i < 2 * n + 1; ++i) {
		if (r > i)
			z[i] = min(z[i - l], r - i);
		while (i + z[i] < 2 * n + 1 && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] > r)
			r = i + z[i], l = i;
	}
	for (int i = 0; i < n; ++i) {
		if (z[i + n + 1] >= n - i) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}