#include <iostream>
using namespace std;
int val[10][2];
int main()
{
	int q;
	scanf("%d",&q);
	for (int i=0;i<10;i++)
	{
		for (int x=0;x<2;x++)
		val[i][x]=x;
	}
	while (q--)
	{
		char c;
		int a;
		getchar();
		scanf("%c %d",&c,&a);
		for (int i=0;i<10;i++)
		{
			bool b=(a&(1<<i));
			for (int x=0;x<2;x++)
			{
				if (c=='&')
				val[i][x]&=b;
				else if (c=='|')
				val[i][x]|=b;
				else
				val[i][x]^=b;
			}
		}
	}
	int an=1023,o=0,xo=0;
	for (int i=0;i<10;i++)
	{
		if (val[i][0]==0 && val[i][1]==0)
		an^=(1<<i);
		else if (val[i][0]==1 && val[i][1]==0)
		xo|=(1<<i);
		else if (val[i][0]==1 && val[i][1]==1)
		o|=(1<<i);
	}
	printf("3\n");
	printf("| %d\n",o);
	printf("& %d\n",an);
	printf("^ %d\n",xo);
}