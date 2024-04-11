#include <iostream>
#include <cstdio>
#include <string>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

int n;
string lin;

void Parse(string &a, string &b, string &c)
{
	while (n) {
		getline(cin, lin); n--;
		int pos = 0;
		while (pos < lin.length() && lin[pos] == ' ') pos++;
		if (pos == lin.length()) continue;
		if (lin[pos] == 't' && lin[pos + 1] == 'r') { a = "try"; return; }
		if (lin[pos] == 't') {
			a = "throw";
			pos += 5;
			int l = lin.find_first_not_of(" (", pos);
			int r = lin.find_first_of(" )", l + 1);
			b = lin.substr(l, r - l);
		} else {
			a = "catch";
			pos += 5;
			int l = lin.find_first_not_of(" (", pos);
			int r = lin.find_first_of(" ,", l + 1);
			b = lin.substr(l, r - l);
			l = lin.find_first_of("\"", r + 1);
			r = lin.find_first_of("\"", l + 1);
			c = lin.substr(l + 1, r - l - 1);
		}
		return;
	}
	a = "end";
}

bool Try(string &ex)
{
	bool res = false;
	string a, b, c;
	while (n) {
		Parse(a, b, c);
		if (a == "try" && Try(ex)) res = true;
		if (a == "catch") {
			if (res && ex == b) { printf("%s\n", c.c_str()); res = false; }
			return res;
		}
		if (a == "throw") { res = true; ex = b; }
	}
}

int main()
{
	scanf("%d", &n); getline(cin, lin);
	while (n) {
		string a, b, c, d;
		Parse(a, b, c);
		if (a == "end") break;
		if (a == "try" && Try(d) || a == "throw") { printf("Unhandled Exception\n"); return 0; }
	}
	return 0;
}