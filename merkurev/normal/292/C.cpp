#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector <string> GD;

string ms(int x)
{
	stringstream ss;
	ss<<x;
	string ans;
	ss>>ans;
	return ans;
}

bool good[10];

bool G[10];
bool gd(int x)
{
	if (x == 0)
		if (!good[0] )
			return false;
	while (x > 0)
	{
		if (!good[x % 10] )
			return false;
		x /= 10;
	}
	return true;
}
void gds(string s)
{
	int len = s.length();
	for (int i = 0; i < len; i++)
		G[s[i] - '0'] = false;
}
bool all(string s)
{
	for (int i = 0; i < 10; i++)
		G[i] = good[i];
	
	gds(s);

	for (int i = 0; i < 10; i++)
		if (G[i] )
			return false;
	return true;
}
bool isPol(string s)
{
	int len = s.length();
	int x = len / 2;
	for (int i = 0; i < x; i++)
	{
		if (s[i] != s[len - i - 1] )
			return false;
	}
	return true;
}
vector <string> ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		good[x] = true;
	}
	if (n > 6)
	{
		printf("0");
		return 0;
	}
	for (int a = 0; a < 256; a++)
	{
		if (gd(a) )
			GD.push_back(ms(a) );
	}
	for (int a = 0; a < GD.size(); a++)
	{
		for (int b = 0; b < GD.size(); b++)
		{
			if (GD[a].length() + GD[b].length() == 6)
			{
				if (!all(GD[a] + GD[b] ) )
					continue;
			}
			for (int c = 0; c < GD.size(); c++)
			{
				if (!all(GD[a] + GD[b] + GD[c] ) )
					continue;
				for (int d = 0; d < GD.size(); d++)
				{
					if (isPol(GD[a]+GD[b]+GD[c]+GD[d] ) )
					{
						ans.push_back(GD[a] + "." + GD[b] + "." + GD[c] + "." + GD[d] );
					}
				}
			}
		}
	}
	printf("%d\n", ans.size() );
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%s\n", ans[i].c_str() );
	}


	return 0;
}