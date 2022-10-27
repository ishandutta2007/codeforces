#include<bits/stdc++.h> 
using namespace std;
int main () { 
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		string s;
		cin >> s;
		if(s.size() == 2 && s[0] >= s[1])
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl << 2 << endl;
			cout << s[0] << " ";
			for(int i = 1; i < s.size(); i++)
			{
				cout << s[i];
			}
			cout << endl;
		}
	}
	return 0;
}