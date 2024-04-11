#include <bits\stdc++.h>
using namespace std;
char s[200000];
stack<char> t;
int a[30];
int b[30];
int d[30];
char c;
int n;
queue<char> u;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	c='a';
	for(int i=0;i<n;i++) a[s[i]-'a']++;
	while(a[c-'a']==0) c++;
	for(int i=0;i<n;i++) d[s[i]-'a']++;
	for(int i=0;i<n;i++)
	{
		t.push(s[i]);
		d[s[i]-'a']--;
		while(c!='z'+1 && d[c-'a']==0 && (t.size()==0 || t.top()>c)) c++;
		while(c!='z'+1 && t.size()>0 && t.top()<=c)
		{
			u.push(t.top());
			t.pop();
			while(c!='z'+1 && d[c-'a']==0 && (t.size()==0 || t.top()>c)) c++;
		}
	}
	while(t.size()>0)
	{
		u.push(t.top());
		t.pop();
	}
	while(u.size()>0)
	{
		printf("%c",u.front());
		u.pop();
	}
	return 0;
}