#include <bits/stdc++.h>
using namespace std;

int T;
int n;
string s;

int main()
{
	cin >> T;
	while (T--) {
		cin >> n;
		cin >> s;
		bool was = false;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				for (int k = j + 1; k < n; k++)
					if (s[i] == s[k] && s[i] != s[j])
						was = true;
		printf("%s\n", was? "NO": "YES");
	}
    return 0;
}