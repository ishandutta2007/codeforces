
#include <bits/stdc++.h>
 
using namespace std;
#define int long long
main() {
	string s;
	cin >> s;
	vector <bool> used(s.size(), false);
	for(int i = 0; i < s.size(); i++)
	{
		int j = i + 1;
		while(j < s.size() && s[j] - 'a' > s[i] - 'a')
		{
			used[j] = true;
			j++;
		}
		i = j - 1;
	}
	for(int i = 0; i < s.size(); i++)
	{
		if(used[i])
		{
			cout << "Ann\n";
		}
		else
		{
			cout << "Mike\n";
		}
	}
    return 0;
}