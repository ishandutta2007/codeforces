#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin >> a >> b;
	int l = 0;
	for (int i = 0; i < a.length(); i++) {
		while (l < b.length() && a[i] != b[l]) l++;
		l++;
	}
	l--;
	int r = b.length() - 1;
	for (int i = a.length() - 1; i >= 0; i--) {
		while (r >= 0 && a[i] != b[r]) r--;
		r--;
	}
	r++;
	printf("%d\n", max(0, r - l));
	return 0;
}