#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n;
string s, res;
int a, b;

int main()
{
	cin >> n >> s;
	int l = (s.length() - 1) / 2;
	int r = n % 2? l: l + 1;
	int i = 0;
	res = s;
	while (i < n) {
		if (l == r) res[l] = s[i++];
		else { res[l] = s[i++]; res[r] = s[i++]; }
		l--; r++;
	}
	cout << res << endl;
	return 0;
}