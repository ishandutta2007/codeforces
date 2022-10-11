#include <iostream>
#include <string.h>
using namespace std;
int solve(string s,char c1,char c2,int n1,int n2,int size)
{
	int i,a=0,b=0;
	for (i=0;i<size;i++)
	{
		if (s[i]==c1 && a!=n1)
		a++;
		if (s[i]==c2 && b!=n2)
		b++;
		if (a==n1 && b==n2)
		return i+1;
	}
	return -1;
}
int abs(int x)
{
	return (x>0)? x:x*-1;
}
int main()
{
	char c1,c2;
	string s;
    int t,n1,n2,n3,n4;
    cin >> t >> n1 >> n2 >> n3 >> n4 >> s;
    if (n3-n1>0)
    c1='E';
    else
    c1='W';
    if (n4-n2>0)
    c2='N';
    else
    c2='S';
    cout << solve(s,c1,c2,abs(n3-n1),abs(n4-n2),t);
}