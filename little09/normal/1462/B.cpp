#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[301]; 
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
		if (a[1]=='2'&&a[2]=='0'&&a[3]=='2'&&a[4]=='0') cout << "YES" << endl;
		else if (a[1]=='2'&&a[2]=='0'&&a[3]=='2'&&a[n]=='0') cout << "YES" << endl;
		else if (a[1]=='2'&&a[2]=='0'&&a[n-1]=='2'&&a[n]=='0') cout << "YES" << endl;
		else if (a[1]=='2'&&a[n-2]=='0'&&a[n-1]=='2'&&a[n]=='0') cout << "YES" << endl;
		else if (a[n-3]=='2'&&a[n-2]=='0'&&a[n-1]=='2'&&a[n]=='0') cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}