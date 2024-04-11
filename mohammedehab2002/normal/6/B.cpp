#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector <char> t;
	vector <char> :: iterator it;
	int l,w,i,x,c1=0,ans=0,no=0;
	char color,c;
	cin >> l >> w >> color;
	t.push_back(color);
	char arr[l][w];
	int cox[l*w],coy[l*w];
	for (i=0;i<l;i++)
	{
		for (x=0;x<w;x++)
		{
			cin >> arr[i][x];
			if (arr[i][x]==color)
			{
				cox[c1]=i;
				coy[c1]=x;
				c1++;
			}
		}
	}
	for (i=0;i<c1;i++)
	{
		if (arr[cox[i]][coy[i]+1]!='.' && coy[i]!=w-1)
		{
			c=arr[cox[i]][coy[i]+1];
			for (it=t.begin();it!=t.end();it++)
			{
				if (c==*it)
				no++;
			}
			if (no==0)
			{
				ans++;
				t.push_back(c);
			}
			else
			no=0;
		}
		if (arr[cox[i]+1][coy[i]]!='.' && cox[i]!=l-1)
		{
			c=arr[cox[i]+1][coy[i]];
			for (it=t.begin();it!=t.end();it++)
			{
				if (c==*it)
				no++;
			}
			if (no==0)
			{
				ans++;
				t.push_back(c);
			}
			else
			no=0;
		}
		if (arr[cox[i]][coy[i]-1]!='.' && coy[i]!=0)
		{
			c=arr[cox[i]][coy[i]-1];
			for (it=t.begin();it!=t.end();it++)
			{
				if (c==*it)
				no++;
			}
			if (no==0)
			{
				ans++;
				t.push_back(c);
			}
			else
			no=0;
		}
		if (arr[cox[i]-1][coy[i]]!='.' && cox[i]!=0)
		{
			c=arr[cox[i]-1][coy[i]];
			for (it=t.begin();it!=t.end();it++)
			{
				if (c==*it)
				no++;
			}
			if (no==0)
			{
				ans++;
				t.push_back(c);
			}
			else
			no=0;
		}
	}
	cout << ans;
}