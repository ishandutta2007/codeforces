#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 55;

ll ways[Maxn];
string s;
vector <int> del;
ll res;

int Dist(int l, int r)
{
	if (l <= r) return r - l;
	return r + s.length() - l;
}

ll F(int x)
{
	x++;
	if (x < 0) return 0;
	return ways[x];
}

int main()
{
	ways[0] = ways[1] = 1;
	for (int i = 2; i < Maxn; i++) ways[i] = ways[i - 2] + ways[i - 1];
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == s[(i + 1) % s.length()])
			if (s[i] == 'A') del.push_back((i + 1) % s.length());
			else del.push_back(i);
	sort(del.begin(), del.end());
	if (del.empty()) {
		int siz = s.length() / 2;
		res = F(siz - 1) + F(siz - 3);
	} else {
		res = 1ll;
		for (int i = 0; i < del.size(); i++) {
			int siz = Dist(del[i] + 1, del[(i + 1) % del.size()]);
			siz /= 2;
			if (s[del[i]] == 'A') siz--;
			if (s[del[(i + 1) % del.size()]] == 'B') siz--;
			res *= F(siz);
		}
	}
	printf("%I64d\n", res);
	return 0;
}