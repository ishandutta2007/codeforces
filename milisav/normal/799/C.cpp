#include <bits\stdc++.h>
using namespace std;
int c[100005];
int d[100005];
int n;
int ac,ad;
int b,p;
int t;
char s[1];
int maxim(int q,int r)
{
	if(q>r) return q;
	else return r;
}
int bitc(int q)
{
	int o=0;
	while(q>0)
	{
		o=maxim(o,c[q]);
		q=q-(q&(-q));
	}
	return o;
}
int bitd(int q)
{
	int o=0;
	while(q>0)
	{
		o=maxim(o,d[q]);
		q=q-(q&(-q));
	}
	return o;
}
void uc(int q,int r)
{
	while(q<=100000)
	{
		c[q]=maxim(c[q],r);
		q=q+(q&(-q));
	}
}
void ud(int q,int r)
{
	while(q<=100000)
	{
		d[q]=maxim(d[q],r);
		q=q+(q&(-q));
	}
}
int main()
{
	scanf("%d %d %d",&n,&ac,&ad);
	int od=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %s",&b,&p,c);
		if(c[0]=='C')
		{
			ac-=p;
			if(i!=0 && ac>=0)
			{
				od=b+maxim(bitc(ac),bitd(ad));
				if(od!=b) t=maxim(t,od);
			}
			ac+=p;
			uc(p,b);
		}
		else
		{
			ad-=p;
			if(i!=0 && ad>=0)
			{
			    od=b+maxim(bitc(ac),bitd(ad));
				if(od!=b) t=maxim(t,od);
			}
			ad+=p;
			ud(p,b);
		}
	}
	printf("%d",t);
	return 0;
}