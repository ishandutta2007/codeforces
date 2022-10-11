#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
int dist[30][30];
int main()
{
	for (int i=0;i<30;i++)
	{
		for (int x=0;x<30;x++)
		{
			if (i!=x)
			dist[i][x]=(1<<29);
		}
	}
	int q;
	string a,b;
	cin >> a >> b >> q;
	while (q--)
	{
		char x,y;
		int c;
		cin >> x >> y >> c;
		if (c<dist[x-'a'][y-'a'])
		dist[x-'a'][y-'a']=c;
	}
	if (a.size()!=b.size())
	{
		cout << -1;
		return 0;
	}
	for (int i=0;i<30;i++)
	{
		for (int x=0;x<30;x++)
		{
			for (int j=0;j<30;j++)
			{
				if (dist[x][i]+dist[i][j]<dist[x][j])
				dist[x][j]=dist[x][i]+dist[i][j];
			}
		}
	}
	int ans=0;
	for (int i=0;i<a.size();i++)
	{
		int an=(1<<29);
		char c;
		for (int x=0;x<30;x++)
		{
			int t1=dist[a[i]-'a'][x],t2=dist[b[i]-'a'][x];
			if (t1==(1<<29) || t2==(1<<29))
			continue;
			if (t1+t2<an)
			{
				an=t1+t2;
				c=x+'a';
			}
		}
		if (an==(1<<29))
		{
			cout << -1;
			return 0;
		}
		ans+=an;
		a[i]=c;
	}
	cout << ans << endl << a;
}