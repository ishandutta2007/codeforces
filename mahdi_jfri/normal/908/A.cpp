#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int main()
{
	string s;
	cin >> s;
	int res = 0;
	for(int i = 0; i < (int)s.size(); i++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			if((s[i] - '0') % 2)
				res++;
		}
		else
		{
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
				res++;
		}
	}
	cout << res << endl;
}