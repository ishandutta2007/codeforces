#include <bits/stdc++.h>
using namespace std;
int k=0;
char c[1];
int v;
int n;
int x1=1024-1;
int x2=0;
int r[1024];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d",c,&v);
		if(c[0]=='&')
		{
			//for(int j=0;j<1024;j++) r[j]&=v;
			x1&=v;
			x2&=v;
		}
		if(c[0]=='^')
		{
			//for(int j=0;j<1024;j++) r[j]^=v;
			x1^=v;
			x2^=v;
		}
		if(c[0]=='|')
		{
			//for(int j=0;j<1024;j++) r[j]|=v;
			x1|=v;
			x2|=v;
		}
	}
	int i=1;
	int l1=0; //&
	int l2=0; //|
	int l3=0; //^
	while(i<1024)
	{
		if((x1&i) && (x2&i)) l2+=i;
		else
		{
			if((x1&i) || (x2&i))
			{
				if((x1&i)) l1+=i;
				else
				{
					l1+=i;
					l3+=i;
				}
			}
			else
			{
				l2+=i;
				l3+=i;
			}
		}
		i=(i<<1);
	}
	/*for(int j=0;j<1024;j++)
	{
		cout<<j<<" "<<r[j]<<" "<<(((j&l1)|l2)^l3)<<endl;
	}*/
	printf("3\n");
	printf("& %d\n",l1);
	printf("| %d\n",l2);
	printf("^ %d\n",l3);
	return 0;
}