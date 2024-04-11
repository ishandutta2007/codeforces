#include <iostream>
#include <string.h>
using namespace std;
string s[3];
int det(char c)
{
	int i,x;
	for (i=0;i<3;i++)
	{
		if (s[i][0]==c && s[i][1]==c && s[i][2]==c)
		return 1;
		if (s[0][i]==c && s[1][i]==c && s[2][i]==c)
		return 1;
	}
	if(s[0][0]==c && s[1][1]==c && s[2][2]==c)
	return 1;
    if(s[2][0]==c && s[1][1]==c && s[0][2]==c)
	return 1;
	return 0;
}
int main()
{
	int i,x,n1=0,n2=0,n3,n4;
	for (i=0;i<3;i++)
	cin >> s[i];
	for (i=0;i<3;i++)
	{
		for (x=0;x<3;x++)
		{
			if (s[i][x]=='X')
			n1++;
			else if (s[i][x]=='0')
			n2++;
		}
	}
	n3=det('X');
	n4=det('0');
	if ((n3 && n4) || n1-n2>1 || n2>n1 || (n4 && n1>n2) || (n3 && n1==n2))
	cout << "illegal";
	else if (n3)
	cout << "the first player won";
	else if (n4)
	cout << "the second player won";
	else if (n1+n2==9)
	cout << "draw";
	else if (n1>n2)
	cout << "second";
	else
	cout << "first";
}