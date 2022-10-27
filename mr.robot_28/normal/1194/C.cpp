#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int q;
	cin >> q;
	for(int k = 0; k < q; k++)
	{
		string s, p, t;
		cin >> s >> t >> p;
		vector <int> A(26), B(26), A1(26);
		for(int i = 0; i < s.size(); i++)
		{
			A[s[i] - 'a']++;
		}
		for(int i = 0; i < p.size(); i++)
		{
			A1[p[i] - 'a']++;
		}
		for(int i = 0; i < t.size(); i++)
		{
			B[t[i] - 'a']++;
		}
		bool flag = true;
		for(int i = 0; i < 26; i++)
		{
			if(A[i] + A1[i] < B[i])
			{
				flag = false;
			}
		}
		int i = 0, j = 0;
		while(i < s.size())
		{
			while(j < t.size() && t[j] != s[i])
			{
				j++;
			}
			if(j == t.size())
			{
				flag = false;
			}
			j++;
			i++;
		}
		if(flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}