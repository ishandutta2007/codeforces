#include <bits/stdc++.h>
using namespace std;
char ch[3];
int main()
{
	scanf("%s", ch);
	int ans = 0;
	if(ch[0] == 'a' || ch[0] == 'h')ans ++;
	if(ch[1] == '1' || ch[1] == '8')ans ++;
	if(ans == 2)printf("3\n");
	else if(ans == 1)printf("5\n");
	else if(ans == 0)printf("8\n");
	return 0;
}