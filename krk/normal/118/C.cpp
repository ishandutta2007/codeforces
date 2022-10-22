#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxd = 10;

int n, k;
string num;
int dist[Maxd], tk[Maxd];
int cur;
string s;
int best = Inf;
string bs;

void Calc(char dig)
{
	fill(dist, dist + Maxd, 0); fill(tk, tk + Maxd, 0);
	for (int i = 0; i < num.length(); i++)
		dist[abs(num[i] - dig)]++;
	cur = 0;
	int nd = k;
	for (int i = 0; i < Maxd; i++) {
		tk[i] = min(nd, dist[i]); nd -= tk[i];
		cur += tk[i] * i;
	}
	s = num;
	for (int i = 0; i < s.size(); i++) {
		int cur = abs(s[i] - dig);
		if (tk[cur] && (dig <= s[i] || dist[cur] == tk[cur])) { s[i] = dig; tk[cur]--; }
		dist[cur]--;
	}
}

int main()
{
	scanf("%d %d", &n, &k); getline(cin, num);
	getline(cin, num);
	for (int i = 0; i < Maxd; i++) {
		Calc(i + '0');
		if (cur < best || cur == best && s < bs) { best = cur; bs = s; }
	}
	printf("%d\n", best);
	printf("%s\n", bs.c_str());
	return 0;
}