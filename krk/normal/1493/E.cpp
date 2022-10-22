#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

char tmp[Maxn];
int n;
string A;
string B;
string res;

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

void Sub1(string &s)
{
	for (int i = int(s.length()) - 1; i >= 0; i--)
		if (s[i] == '0') s[i] = '1';
		else { s[i]--; break; }
}

string lastTwo(const string &s)
{
	if (n == 1) return "0" + string(1, s[int(s.length()) - 1]);
	return s.substr(int(s.length()) - 2);
}

int main()
{
	scanf("%d", &n);
	Read(A);
	Read(B);
	if (A == B) { printf("%s\n", A.c_str()); return 0; }
	if (A[0] == '0') { printf("%s\n", string(n, '1').c_str()); return 0; }
	if (A != string(n, '0')) Sub1(A);
	bool one = false, zer = false;
	for (int i = 0; i < 4 && A <= B; i++) {
		string my = lastTwo(B);
		if (my == "00") {
			if (res.size() == 0) res = B;
		} else if (my == "10") {
			if (res.size() == 0) {
				res = B;
				res[int(res.size()) - 1] = '1';
			}
		} else if (my == "01") one = true;
		 	   else if (my == "11") zer = true;
		if (B == string(n, '0')) break;
		Sub1(B);
	}
	if (res[int(res.size()) - 1] == '0' && one ||
		res[int(res.size()) - 1] == '1' && !zer)
		res[int(res.size()) - 1] = '1' - res[int(res.size()) - 1] + '0';
	printf("%s\n", res.c_str());
    return 0;
}