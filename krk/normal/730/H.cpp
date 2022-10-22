#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, m;
string s[Maxn];
bool todel[Maxn];
string pat;

bool Check(const string &pat, const string &str)
{
	if (pat.size() != str.size()) return false;
	for (int i = 0; i < pat.size(); i++)
		if (pat[i] != '?' && str[i] != pat[i]) return false;
	return true;
}

bool Refine(string &pat, const string &str)
{
	if (pat.size() != str.size()) return false;
	for (int i = 0; i < pat.size(); i++)
		if (pat[i] != '?' && str[i] != pat[i]) pat[i] = '?';
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	while (m--) {
		int a; scanf("%d", &a);
		todel[a] = true;
	}
	int ind = 0;
	while (!todel[ind]) ind++;
	string pat = s[ind];
	for (int i = 1; i <= n; i++) if (todel[i])
		if (!Refine(pat, s[i])) { printf("No\n"); return 0; }
	for (int i = 1; i <= n; i++) if (!todel[i])
		if (Check(pat, s[i])) { printf("No\n"); return 0; }
	printf("Yes\n");
	printf("%s\n", pat.c_str());
	return 0;
}