#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int Maxd = 8;
const string cand[Maxd] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int n;
string s;

bool Check(const string &cand)
{
	if (s.length() != cand.length())
		return false;
	for (int i = 0; i < s.length(); i++)
		if (s[i] != '.' && s[i] != cand[i])
			return false;
	return true;
}

int main()
{
	cin >> n;
	cin >> s;
	for (int i = 0; i < Maxd; i++)
		if (Check(cand[i])) {
			printf("%s\n", cand[i].c_str());
			break;
		}
	return 0;
}