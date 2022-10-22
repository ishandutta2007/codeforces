#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
	int i;
	string a, b;
	cin >> a >> b;
	for (i = a.size() - 1; i >= 0; i--)
		if (a[i] < 'z') {
			a[i]++;
			break;
		}
		else
			a[i] = 'a';
	if (a == b)
		cout << "No such string";
	else
		cout << a;
	return 0;
}