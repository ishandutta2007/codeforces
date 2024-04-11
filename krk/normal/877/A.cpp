#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 5;
const string nams[Maxn] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

string str;
int res;

int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		for (int j = 0; j < Maxn; j++) if (i + nams[j].length() <= str.length())
			if (str.substr(i, nams[j].length()) == nams[j]) res++;
	printf("%s\n", res == 1? "YES": "NO");
	return 0;
}