#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n;
string s;
int A, C, G, T;

int Min() { return min(min(A, C), min(G, T)); }

int main()
{
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'A') A++;
		else if (s[i] == 'C') C++;
		else if (s[i] == 'G') G++;
		else if (s[i] == 'T') T++;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '?')
			if (A == Min()) { s[i] = 'A'; A++; }
			else if (C == Min()) { s[i] = 'C'; C++; }
			else if (G == Min()) { s[i] = 'G'; G++; }
			else { s[i] = 'T'; T++; }
	if (A == C && C == G && G == T)
		cout << s << endl;
	else cout << "===" << endl;
	return 0;
}