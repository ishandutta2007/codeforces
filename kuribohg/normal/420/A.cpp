#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int len;
char str[100010];
bool ok[1000];
bool yes=true;
int main()
{
	ok['A']=ok['H']=ok['I']=ok['M']=ok['O']=ok['T']=ok['U']=ok['V']=ok['W']=ok['X']=ok['Y']=true;
	scanf("%s",str);
	len=strlen(str);
	for(int i=0;i<len;i++)
		if(str[i]==str[len-i-1]&&ok[str[i]]) continue;
		else yes=false;
	if(yes) puts("YES");
	else puts("NO");
	return 0;
}