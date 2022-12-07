#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int len;
bool digit,upper,lower;
char a[201];
int main()
{
	scanf("%s",a);
	len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]>='a'&&a[i]<='z') upper=true;
		else if(a[i]>='A'&&a[i]<='Z') lower=true;
		else if(a[i]>='0'&&a[i]<='9') digit=true;
	}
	if(len>=5&&upper&&lower&&digit) puts("Correct");
	else puts("Too weak");
	return 0;
}