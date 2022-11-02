#include <bits/stdc++.h>
using namespace std;

int N;
vector <string> ten = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"},
one = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"},
special = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

int main()
{
	cin >> N;
	if (!N){ puts("zero"); return 0; }
	int t = N/10, o = N%10;
	if (t == 1) cout << special[o] << endl;
	else if (!t) cout << one[o] << endl;
	else if (!o) cout << ten[t] << endl;
	else cout << ten[t] << "-" << one[o] << endl;
}