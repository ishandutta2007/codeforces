#include <bits/stdc++.h>
using namespace std;

string s;
map <char, int> M;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		M[s[i]]++;
	if (M.size() == 1) printf("No\n");
	else if (M.size() == 2 || M.size() == 3) {
		int nd = 4 - int(M.size());
		for (map <char, int>::iterator it = M.begin(); it != M.end(); it++)
			if (it->second >= 2) nd--;
		printf("%s\n", nd <= 0? "Yes": "No");
	} else if (M.size() == 4) printf("Yes\n");
	else printf("No\n");
	return 0;
}