#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string s, t;
int c, d;
int a, b;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'H') c++;
		else d++;
	b = int(sqrt(double(d)) + 0.5);
	if (b * b != d || c % (1 + b)) printf("No\n");
	else {
		a = c / (1 + b);
		int i = 0;
		while (i < s.length() && s[i] != 'Q') i++;
		if (i == s.length()) printf("Yes\n");
		else if (i % 2) printf("No\n");
		else {
			int l = i / 2, r = i / 2 + a + b;
			int hasa = 0, hasb = 0;
			for (int j = l; j < s.length() && j < r; j++)
				if (s[j] == 'H') hasa++;
				else hasb++;
			if (a != hasa || b != hasb) printf("No\n");
			else {
				t.resize(s.length()); int len = 0;
				for (i = l; i < r; i++)
					if (s[i] == 'H') t[len++] = 'H';
					else for (int j = l; j < r; j++)
							t[len++] = s[j];
				printf("%s\n", s == t? "Yes": "No");
			}
		}
	}
	return 0;
}