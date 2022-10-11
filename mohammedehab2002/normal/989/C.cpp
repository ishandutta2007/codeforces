#include <iostream>
using namespace std;
char ans[50][50];
int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	for (int i=0;i<50;i++)
	{
		for (int x=0;x<50;x++)
		ans[i][x]='A'+i/25;
	}
	a--;
	b--;
	for (int i=0;i<50;i+=2)
	{
		for (int x=0;x<50;x+=2)
		{
			if (b)
			{
				ans[i][x]='B';
				b--;
			}
			else if (c)
			{
				ans[i][x]='C';
				c--;
			}
			else if (d)
			{
				ans[i][x]='D';
				d--;
			}
			else if (a && ans[i][x]!='A')
			{
				ans[i][x]='A';
				a--;
			}
		}
	}
	cout << 50 << ' ' << 50 << endl;
	for (int i=0;i<50;i++)
	{
		for (int x=0;x<50;x++)
		cout << ans[i][x];
		cout << endl;
	}
}