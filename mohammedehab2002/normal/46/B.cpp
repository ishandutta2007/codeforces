#include <iostream>
#include <string.h>
using namespace std;
void output(int z)
{
	if (z==0)
	cout << "S";
	else if (z==1)
	cout << "M";
	else if (z==2)
	cout << "L";
	else if (z==3)
	cout << "XL";
	else
	cout << "XXL";
	cout << "\n";
}
int main()
{
	int t[5],k,i,x;
	for (i=0;i<5;i++)
	cin >> t[i];
	cin >> k;
	string s[k];
	int ans[k][5];
	for (i=0;i<k;i++)
	{
		cin >> s[i];
		if (s[i]=="S")
		{
			for (x=0;x<5;x++)
			ans[i][x]=x;
		}
		else if (s[i]=="M")
		{
			ans[i][0]=1;
			ans[i][1]=2;
			ans[i][2]=0;
			ans[i][3]=3;
			ans[i][4]=4;
		}
		else if (s[i]=="L")
		{
			ans[i][0]=2;
			ans[i][1]=3;
			ans[i][2]=1;
			ans[i][3]=4;
			ans[i][4]=0;
		}
		else if (s[i]=="XL")
		{
			ans[i][0]=3;
			ans[i][1]=4;
			ans[i][2]=2;
			ans[i][3]=1;
			ans[i][4]=0;
		}
		else
		{
			for (x=4;x>=0;x--)
			ans[i][(4-x)]=x;
		}
	}
	for (i=0;i<k;i++)
	{
		for (x=0;x<5;x++)
		{
			if (t[ans[i][x]]>0)
			{
				output(ans[i][x]);
				t[ans[i][x]]--;
				goto out;
			}
		}
		out: i++;
		i--;
	}
}