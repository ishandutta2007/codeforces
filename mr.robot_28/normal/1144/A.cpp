#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		vector <int> W(26, 0);
		for(int j = 0; j < s.size(); j++)
		{
			W[s[j] - 'a']++;
		}
		bool f = true;
		bool k = true;
		vector <int> K;
		for(int j = 0; j < 26; j++)
		{
			if(W[j]> 1)
			{
				f = false;
			}
			if(W[j] == 1)
			{
				K.push_back(j);
			}
		}
		for(int j = 0; j < K.size() - 1; j++)
		{
			if(j >= int(K.size()) - 1)
			{
				break;
			}
			else if(K[j] != K[j + 1] - 1)
			{
				k = false;
			}
		}
		if(k && f)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}