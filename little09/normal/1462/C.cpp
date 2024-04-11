#include<bits/stdc++.h>
using namespace std;
int n,m;
int u[10];
inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
int main()
{
	int T=read();
	while (T--)
	{
		cin>>n;
		if (n>45) cout << "-1" << endl;
		else 
		{
			int cnt=0,tot=9;
			while (n)
			{
				cnt++;
				if (n>=tot) u[cnt]=tot,n-=tot;
				else
				{
					u[cnt]=n;
					break;
				}
				tot--;
			}
			for (int i=cnt;i>=1;i--) cout << u[i];
			cout << endl;
		}
	}
	return 0;
}