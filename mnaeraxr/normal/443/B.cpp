#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ady;
vector<bool> mk;

int main()
{
	string s;
	int k;
	cin >> s >> k;

	for (int i = 0; i < k; ++i)
		s += "*";

	int best = 0;
	for (int i = 0; i < (int)s.length(); ++i){
		for (int j = best + 2; i + j <= (int)s.length(); j += 2)
		{
			bool ok = true;
			for (int k = 0; k < j / 2 && ok; ++k){
				if (s[i + k + j / 2] != '*' && s[i + k] != s[i + k + j / 2]) ok = false;
			}
			if (ok) best = j;
		}
	}

	cout << best << endl;
}