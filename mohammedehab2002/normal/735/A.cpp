#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	bool b=1;
	int n,k;
	string s;
	cin >> n >> k >> s;
	int pos=s.find('G'),pos2=s.find('T');
	if (pos<pos2)
	{
		for (int i=pos;i<=pos2;i+=k)
		{
			if (s[i]=='#')
			b=0;
		}
	}
	else
	{
		for (int i=pos;i>=pos2;i-=k)
		{
			if (s[i]=='#')
			b=0;
		}
	}
	if (b && abs(pos2-pos)%k==0)
	cout << "YES";
	else
	cout << "NO";
}