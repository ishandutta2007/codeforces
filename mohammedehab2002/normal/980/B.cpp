#include <iostream>
using namespace std;
string s[4];
int main()
{
	int n,k;
	cin >> n >> k;
	if (k%2==0)
	{
		printf("YES\n");
		for (int i=0;i<4;i++)
		{
			for (int x=0;x<n;x++)
			{
				if (i && x && i!=3 && x!=(n-1) && x<=k/2)
				printf("#");
				else
				printf(".");
			}
			printf("\n");
		}
		return 0;
	}
	else
	{
		printf("YES\n");
		for (int i=0;i<4;i++)
		s[i]=string(n,'.');
		for (int i=0;i<=min(k,n-2)/2;i++)
		{
			s[1][n/2-i]='#';
			s[1][n/2+i]='#';
		}
		if (k>n-2)
		{
			k-=(n-2);
			for (int i=1;i<=k/2;i++)
			{
				s[2][n/2-i]='#';
				s[2][n/2+i]='#';
			}
		}
		for (int i=0;i<4;i++)
		cout << s[i] << endl;
	}
}