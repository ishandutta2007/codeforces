#include<iostream>
#include<string>
using namespace std;
string s[1111];
int n;
void print(int i,int j,int k)
{
	cout<<"YES"<<endl;
	for (int ii=1;ii<=n;ii++)
	{
		for (int jj=0;jj<=4;jj++)
		{
			if (ii==i && (jj==j || jj==k))
			{
				cout<<"+";
			}
			else cout<<s[ii][jj];
		}
		cout<<endl;
	}
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>s[i];
	for (int i=1;i<=n;i++)
	{
		if (s[i][0]=='O' && s[i][1]=='O')
		{
			print(i,0,1);
			return 0;
		}
		if (s[i][3]=='O' && s[i][4]=='O')
		{
			print(i,3,4);
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}