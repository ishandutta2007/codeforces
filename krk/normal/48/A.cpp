#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string a, b, c;

bool Better(const string &a, const string &b)
{
	return a == "rock" && b == "scissors" ||
		   a == "scissors" && b == "paper" ||
		   a == "paper" && b == "rock";
}

int main()
{
	cin >> a >> b >> c;
	if (Better(a, b) && Better(a, c)) printf("F\n");
	else if (Better(b, a) && Better(b, c)) printf("M\n");
	else if (Better(c, a) && Better(c, b)) printf("S\n");
	else printf("?\n");
	return 0;
}