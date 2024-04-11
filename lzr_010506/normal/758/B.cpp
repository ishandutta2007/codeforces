#include <bits/stdc++.h>
using namespace std;
char ch[210];
char mb[4];
int cnt[200];
int main()
{
	scanf("%s", ch);
	int n = strlen(ch);
	int st = 0;
	n += st;
	int s = 0;
	for(int i = 0; i < n; i ++, s ++)
	{
		s %= 4;
		if(ch[i] == '!') continue;
		mb[s] = ch[i];
	}
	s = 0;
	for(int i = 0; i < n; i ++, s ++)
    {
        s %= 4;
        if(ch[i] == '!')
			cnt[mb[s]] ++;
    }

	cout << cnt['R'] << " ";
	cout << cnt['B'] << " ";
	cout << cnt['Y'] << " ";
	cout << cnt['G'];
	return 0;
}