#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
#include<stack>
#include<string>
using namespace std;
int main()
{
	bool p = false;
	string a, b;
	cin >> a >> b;
	if(b.size() < a.size())
	{
		p = true;
	}
	else if(b.size() > a.size())
	{
		cout << "need tree";
		return 0;
	}
	int j = 0;
	for(int i = 0; i < a.size(); i++)
	{
		if(j >= b.size())
		{
			break;
		}
		else if(a[i] == b[j])
		{
			j++;
		}
	}
	if(j == b.size() && p)
	{
		cout << "automaton";
		return 0;
	}
	else
	{
		vector <int> A(26, 0), B(26, 0);
		for(int i = 0; i < a.size(); i++)
		{
			A[a[i] - 'a']++;
		}
		for(int j = 0; j < b.size(); j++)
		{
			B[b[j] - 'a']++;
		}
		for(int i = 0; i < 26; i++)
		{
			if(A[i] < B[i])
			{
				cout << "need tree";
				return 0;
			}
		}
		if(a.size() == b.size())
		{
			cout << "array";
		}
		else
		{
			cout << "both";
		}
	}
	return 0;
}