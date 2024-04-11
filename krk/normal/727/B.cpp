#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

string s;
ll sum;

int main()
{
	cin >> s;
	int pnt = 0;
	while (pnt < s.length())
		if (islower(s[pnt])) pnt++;
		else {
			int j = pnt;
			while (j < s.length() && (isdigit(s[j]) || s[j] == '.')) j++;
			string tmp = s.substr(pnt, j - pnt);
			if (tmp.length() < 3 || tmp[tmp.length() - 3] != '.') tmp += ".00";
			ll cur = 0;
			for (int z = 0; z < tmp.length(); z++)
				if (tmp[z] != '.') cur = cur * 10 + (tmp[z] - '0');
			sum += cur;
			pnt = j;
		}
	stringstream ss; ss << sum / 100;
	string pr; ss >> pr;
	for (int i = 0; i < pr.length(); i++) {
		printf("%c", pr[i]);
		if (i != pr.length() - 1 && (pr.length() - 1 - i) % 3 == 0) printf(".");
	}
	if (sum % 100) printf(".%d%d", int(sum % 100 / 10), int(sum % 10));
	printf("\n");
	return 0;
}