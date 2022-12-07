#include <bits/stdc++.h>
using namespace std;
int flag;
char ch[100010];
inline int nxt(int x)
{
	if(x == 'a') return 'z';
	return x - 1;
}

int main()
{
	gets(ch);
	for(int i = 0; ch[i]; i ++)
		if(nxt(ch[i]) < ch[i])
			if(flag) ch[i] = nxt(ch[i]);
			else flag = 1, ch[i] = nxt(ch[i]);
		else if(flag) break;
	if(!flag)
		for(int i = 0; ch[i]; i ++)
			if(!ch[i + 1])
				ch[i] = nxt(ch[i]);
	printf("%s", ch);
	return 0;
}