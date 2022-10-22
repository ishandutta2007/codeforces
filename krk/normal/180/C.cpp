#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

string s;
int cnt[Maxn];
int best = 1000000000;

int main()
{
	getline(cin, s);
	cnt[0] = 0;
	for (int i = 1; i <= s.length(); i++) cnt[i] = cnt[i - 1] + (isupper(s[i - 1]) > 0);
	for (int i = 0; i <= s.length(); i++) best = min(best, i - cnt[i] + cnt[s.length()] - cnt[i]);
	printf("%d\n", best);
	return 0;
}