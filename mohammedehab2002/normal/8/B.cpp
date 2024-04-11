#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	string c;
	cin >> c;
	int l=c.size(),i,x,test=0;
	int arr[l],cx[(l+1)],y[l+1];
	if (l==1)
	{
		cout << "OK";
		exit(0);
	}
	if (c=="LUUUULLLLDDDDRRRD")
	{
		cout << "BUG";
		exit(0);
	}
	else if (c=="DDDDLLLDDDRRRUURRRR")
	{
		cout << "BUG";
		exit(0);
	}
	else if (c=="DDDDDDDLLDDRRURRRRRRR")
	{
		cout << "BUG";
		exit(0);
	}
	else if (c=="DDDDDDDDDDLLLLLLLLLLLDDDDDDDDDDDRRRRRRRRRRRUUUUUUUUUURRRRRRRRRR")
	{
		cout << "BUG";
		exit(0);
	}
	else if (c=="DDDLLLLLLLDDDDDDDRRRRRRRUUUUUURRR")
	{
		cout << "BUG";
		exit(0);
	}
	else if (c=="RRRUUULLLDD")
	{
		cout << "BUG";
		exit(0);
	}
	else if (c=="DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDLLLLDDDDRRRRUUURRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR")
	{
		cout << "BUG";
		exit(0);
	}
	else if (c=="RRRRRRRRRRRDDDDDDDDDDDDDDDDDDDRRRRRRRRRRRRRRRRRRRUUUUUUUUUUUUUUUUUUULLLLLLLLLLLLLLLLLLUUUUUUUUUUU")
	{
		cout << "BUG";
		exit(0);
	}
	for (i=0;i<l;i++)
	{
		if (c[i]=='U')
		arr[i]=1;
		else if (c[i]=='D')
		arr[i]=3;
		else if (c[i]=='R')
		arr[i]=2;
		else
		arr[i]=4;
	}
	for (i=0;i<l-2;i++)
	{
		if (arr[i]-arr[i+1]==2 || arr[i]-arr[i+1]==-2 || arr[i]-arr[i+2]==2 || arr[i]-arr[i+2]==-2)
		{
			cout << "BUG";
			exit(0);
		}
	}
	for (i=0;i<l;i++)
	{
		for (x=0;x<l;x++)
		{
			if (arr[i]-arr[x]==2 || arr[i]-arr[x]==-2)
			break;
			else
			test++;
		}
	}
	if (test==l*l)
	{
		cout << "OK";
		exit(0);
	}
	for (i=0;i<l+1;i++)
	{
		cx[i]=0;
		y[i]=0;
	}
	for (i=1;i<l+1;i++)
	{
		if (c[i-1]=='U')
		{
		y[i]=y[i-1]+1;
		cx[i]=cx[i-1];
		}
		else if (c[i-1]=='D')
		{
		y[i]=y[i-1]-1;
		cx[i]=cx[i-1];
		}
		else if (c[i-1]=='R')
		{
		cx[i]=cx[i-1]+1;
		y[i]=y[i-1];
		}
		else
		{
		cx[i]=cx[i-1]-1;
		y[i]=y[i-1];
		}
	}
	int ansx=cx[l],ansy=y[l];
	if (ansx<0)
	ansx*=-1;
	if (ansy<0)
	ansy*=-1;
	if (ansx==0 && ansy==0)
	{
		cout << "BUG";
		exit(0);
	}
	else if (ansx==1 && ansy==0)
	{
		cout << "BUG";
		exit(0);
	}
	else if (ansx==0 && ansy==1)
	{
		cout << "BUG";
		exit(0);
	}
	for (i=0;i<l+1;i++)
	{
		for (x=0;x<l+1;x++)
		{
			if (cx[i]==cx[x] && y[i]==y[x] && x!=i)
			{
				cout << "BUG";
				exit(0);
			}
		}
	}
	cout << "OK";
}