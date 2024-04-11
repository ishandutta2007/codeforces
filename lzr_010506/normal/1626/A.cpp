#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		int a[26] = {0};
		string s;
		cin >> s;
		int m = s.length();
		for(int i = 0; i < m; i ++) a[s[i] - 'a'] ++;
		for(int i = 0; i < 26; i ++)
			if(a[i])
				for(int j = 0; j < a[i]; j ++)
				{
					char t = i + 'a';
					cout << t;
				}
		cout << "\n";
	}
	return 0;
}