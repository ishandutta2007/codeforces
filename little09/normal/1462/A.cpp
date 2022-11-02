#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[301]; 
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
		for (int i=1;i<=n;i++) cin >>a[i];
		int cnt1=1,cnt2=n;
		for (int i=1;i<=n;i++)
		{
			if (i%2==1)
			{
				cout << a[cnt1] << " ";
				cnt1++;
			}
			else
			{
				cout << a[cnt2] << " ";
				cnt2--;
			}
		}
		cout << endl;
	}
	return 0;
}