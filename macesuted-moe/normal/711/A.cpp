#include<bits/stdc++.h>
using namespace std;
char a[1005][6];
int main()
{
	int n;
	cin>>n;
	bool b=true;
	getchar();
	for(int i=1;i<=n;i++)
	{
		char a1,a2,b1,b2;
		a1=getchar();
		a2=getchar();
		getchar();
		b1=getchar();
		b2=getchar();
//		cout<<a1<<a2<<b1<<b2<<endl;
		getchar();
		if(b&&a1==a2&&a1=='O') a1=a2='+',b=false;
		if(b&&b1==b2&&b1=='O') b1=b2='+',b=false;
//		cout<<(bool)(a1==a2)<<(bool)(b1==b2)<<(bool)(a1=='O')<<endl;
		a[i][1]=a1;
		a[i][2]=a2;
		a[i][3]='|';
		a[i][4]=b1;
		a[i][5]=b2;
	}
	if(b)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
			cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}