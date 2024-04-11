#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int Maxn = 100005;

string s;
string w[Maxn];
int pnt = 0;
int res;

int main()
{
	ios_base::sync_with_stdio(0);
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '0') w[pnt] += s[i];
		else w[++pnt] = s[i];
	string cur;
	for (int i = 1; i <= pnt; i++) {
		if (cur.size() > w[i].size() || cur.size() == w[i].size() && cur >= w[i]) res++;
		else res = 1;
		cur += w[i];
	}
	printf("%d\n", res);
	return 0;
}