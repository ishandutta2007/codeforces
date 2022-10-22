#include<bits/stdc++.h>
using namespace std;
char ch[10],s[10];
int main()
{
	scanf("%s",ch);
	for (int i=1;i<=5;i++){scanf("%s",s);if(s[0]==ch[0]||s[1]==ch[1]) {puts("YES");return 0;}}
	puts("NO");
}