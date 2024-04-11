#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int Maxn = 100005;

string s;
bool opened;
int col[Maxn], id;

int main()
{
	getline(cin, s); s += " ";
	int p = s.find_first_not_of(' ');
	while (p < s.length())
		if (s[p] == '"') {
			int nxt = s.find_first_of('"', p + 1);
			printf("<%s>\n", s.substr(p + 1, nxt - p - 1).c_str());
			p = s.find_first_not_of(' ', nxt + 1);
		} else {
			int nxt = s.find_first_of(' ', p + 1);
			printf("<%s>\n", s.substr(p, nxt - p).c_str());
			p = s.find_first_not_of(' ', nxt + 1);
		}
	return 0;
}