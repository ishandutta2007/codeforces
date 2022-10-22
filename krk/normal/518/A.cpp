#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string a, b;

int main()
{
	cin >> a >> b;
	for (int i = a.length() - 1; i >= 0; i--)
		if (a[i] != 'z') {
			a[i]++;
			if (a != b) cout << a << endl;
			else cout << "No such string" << endl;
			return 0;
		} else a[i] = 'a';
	cout << "No such string" << endl;
	return 0;
}