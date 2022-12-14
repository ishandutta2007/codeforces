#include<iostream>
#include<cstdio>
#include<deque>
#include<cstring>
using namespace std;
char s[1111111];
deque<int> q;
int n;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	q.push_back(n); 
	for (int i=n-2;i>=0;i--)
	{
		if (s[i]=='l') q.push_back(i+1);
		else q.push_front(i+1);  
	}
	for (int i=0;i<n;i++)
	{
		printf("%d\n",q[i]);
	}
	return 0;
}