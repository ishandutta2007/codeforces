#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
map<char, int> mp;
char c[10100];
int main()
{
	mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = mp['y'] = 1;
	int n; scanf("%d", &n);
	scanf("%s", c);
	for(int i = 0; i < n; i++)
	{
		if(mp[c[i]] == 0) printf("%c", c[i]), i++;
		if(mp[c[i]] == 1) printf("%c", c[i]);
		while(i < n && mp[c[i]] == 1)
		{
			i++;
		}
		i--;
	}
	return 0;
}