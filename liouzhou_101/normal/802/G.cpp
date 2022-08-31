#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

char t[] = "heidi";

int main()
{
	
	string s;
	cin >> s;
	for (int i = 0, j = 0; i < 5; ++ i)
	{
		while (j < s.size())
		{
			if (s[j] == t[i])
				break;
			j ++;
		}
		if (j == s.size())
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	
	return 0;
}