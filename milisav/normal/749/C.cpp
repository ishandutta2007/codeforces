#include <iostream>
#include <cstdio>
using namespace std;
struct e
{
	int pr;
	int sl;
	int v;
};
e a[200004];
int d,r;
int dt,rt;
int n;
char s[200005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++)
	{
		a[i].sl=i+1;
		a[i].pr=i-1;
		if(s[i]=='D') 
		{
			dt++;
			a[i].v=1;
		}
		else
		{
			rt++;
			a[i].v=-1;
		}
	}
	a[0].pr=n-1;
	a[n-1].sl=0;
	d=0;
	r=0;
	int j,k;
	for(int i=0;dt!=0 && rt!=0;i=a[i].sl)
	{
		if(a[i].v==1)
		{
			if(d>0)
			{
				j=a[i].pr;
				k=a[i].sl;
				a[j].sl=k;
				a[k].pr=j;
				dt--;
				d--;
			}
			else
			{
				r++;
			}
		}
		else
		{
			if(r>0)
			{
				j=a[i].pr;
				k=a[i].sl;
				a[j].sl=k;
				a[k].pr=j;
				rt--;
				r--;
			}
			else
			{
				d++;
			}
		}
	}
	if(rt==0) printf("D\n");
	else printf("R\n");
	return 0;
}