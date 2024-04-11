#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 27;

string s;
ll res[Maxn];
int cnt[Maxn], cols;

ll Get(int len)
{
	ll res = 0;
	int r = 0;
	for (int l = 0; l < s.length(); l++) {
		while (r < s.length() && cols <= len) {
			if (cnt[s[r] - 'a']++ == 0) cols++;
			r++;
		}
		res += cols <= len? r - l: r - l - 1;
		if (--cnt[s[l] - 'a'] == 0) cols--;
	}
	return res;
}

int main()
{
	getline(cin, s);
	int mx = -1;
	for (int i = Maxn - 1; i >= 0; i--) {
		res[i] = Get(i);
		if (i + 1 < Maxn) {
			res[i + 1] -= res[i];
			if (res[i + 1] && mx == -1) mx = i + 1;
		}
	}
	printf("%d\n", mx);
	for (int i = 1; i <= mx; i++)
		printf("%I64d\n", res[i]);
	return 0;
}