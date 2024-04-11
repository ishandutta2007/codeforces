#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int sumA=s[0]+s[1]+s[2]-3*'0',sumB=s[3]+s[4]+s[5]-3*'0';
	if (sumA==sumB)
	{
		cout << 0;
		return 0;
	}
	string d;
	if (sumA>sumB)
	d="000999";
	else
	d="999000";
	int dif=abs(sumA-sumB);
	for (int i=1;i<=6;i++)
	{
		int cur=0;
		for (int x=1;x<6;x++)
		{
			if (abs(s[x]-d[x])>abs(s[cur]-d[cur]))
			cur=x;
		}
		dif-=abs(s[cur]-d[cur]);
		s[cur]=d[cur];
		if (dif<=0)
		{
			printf("%d",i);
			return 0;
		}
	}
}