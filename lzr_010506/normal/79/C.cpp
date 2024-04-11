#include <bits/stdc++.h>
using namespace std;
int mx = -1, p = -1;
string a[100];
int n;
string s;
int main()
{
	cin>>s;
	cin>>n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	int l = 0;
	for(int i = 0; i < s.size(); i ++)
	{
		for (int j = 0; j < n; j ++)
			if ((int)a[j].size() <= i - l + 1 && s.substr(i - a[j].size() + 1, a[j].size()) == a[j])
				l = i - a[j].size() + 2;
		if (i - l + 1 > mx)
		{
			mx = i - l + 1;
			p = l;
		}
	}
	cout << mx << " " << p << endl;
	return 0;
}