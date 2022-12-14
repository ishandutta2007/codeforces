#include<iostream>
#include<cstdio> 
using namespace std;
int n,m;
char c;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>c;
			getchar();
			if (c!='W' && c!='G' && c!='B') 
			{
				cout<<"#Color"<<endl;
				return 0;
			}
		}
	}
	cout<<"#Black&White"<<endl;
	return 0;
}