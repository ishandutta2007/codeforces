#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;
char a[100010];
int main()
{
	scanf("%s",a);
	if(!isupper(a[0])) a[0]=a[0]-'a'+'A';
	puts(a);
	return 0;
}