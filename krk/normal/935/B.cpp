#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int x, y;
vector <int> seq;
int res;

int main()
{
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'R') x++;
		else if (s[i] == 'U') y++;
		if (x < y) seq.push_back(2);
		else if (x > y) seq.push_back(1);
	}
	for (int i = 1; i < seq.size(); i++)
		if (seq[i] != seq[i - 1]) res++;
	printf("%d\n", res);
	return 0;
}