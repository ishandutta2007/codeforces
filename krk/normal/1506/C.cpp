#include <bits/stdc++.h>
using namespace std;

int T;
string a;
string b;

int main()
{
	cin >> T;
	while (T--) {
		cin >> a;
		cin >> b;
		int mx = 0;
		for (int i = 0; i < a.length(); i++)
			for (int j = 0; j < b.length(); j++) {
				int l = 0;
				while (i + l < a.length() && j + l < b.length() && a[i + l] == b[j + l])
					l++;
				mx = max(mx, l);
			}
		printf("%d\n", int(a.length()) + int(b.length()) - 2 * mx);
	}
    return 0;
}