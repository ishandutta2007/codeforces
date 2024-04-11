#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxl = 26;

string a, b;
int freqa[Maxl], freqb[Maxl];
ll freqc[Maxl];
int x;

bool Ok(ll p)
{
	ll res = 0;
	for (int i = 0; i < Maxl; i++) {
		ll add = p * ll(freqb[i]) - freqa[i];
		if (add > 0) {
			res += add;
			freqc[i] = add;
		} else freqc[i] = 0;
	}
	return res <= x;
}

int main()
{
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) if (a[i] != '?')
		freqa[a[i] - 'a']++;
	else x++;
	for (int i = 0; i < b.length(); i++)
		freqb[b[i] - 'a']++;
	int lef = 0, rig = 10000000;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Ok(mid)) lef = mid + 1;
		else rig = mid - 1;
	}
	Ok(lef - 1);
	int p = 0;
	for (int i = 0; i < a.length(); i++) if (a[i] == '?') {
		while (p < Maxl && freqc[p] == 0) p++;
		if (p < Maxl) { a[i] = 'a' + p; freqc[p]--; }
		else a[i] = 'a';
	}
	printf("%s\n", a.c_str());
	return 0;
}