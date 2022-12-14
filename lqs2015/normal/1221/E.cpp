#include<bits/stdc++.h>
using namespace std;
int test,n,cnt,ct,a[333333],cur,A,B,pos;
bool f,win,upd;
char s[333333];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&A,&B);
		scanf("%s",s);
		n=strlen(s);
		cur=cnt=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='X')
			{
				if (cur) a[++cnt]=cur;
				cur=0;
			}
			else cur++;
		}
		if (cur) a[++cnt]=cur;
		f=0;ct=0;
		for (int i=1;i<=cnt;i++)
		{
			if (a[i]>A+4*B-2) f=1;
			if (a[i]>=2*B) ct++;
			if (a[i]<A && a[i]>=B) f=1;
		}
		if (f || ct>1) 
		{
			printf("NO\n");
			continue;
		}
		if (!ct)
		{
			for (int i=1;i<=cnt;i++)
			{
				if (a[i]>=A) ct++;
			}
			if (ct&1) printf("YES\n");
			else printf("NO\n");
		}
		else
		{
			pos=0;win=0;
			for (int i=1;i<=cnt;i++)
			{
				if (a[i]>=A && a[i]<2*B) pos++;
			}
			for (int i=1;i<=cnt;i++)
			{
				if (a[i]>=2*B)
				{
					if (a[i]>=A+A && a[i]<=A+B-1+2*B-1) 
					{
						if (pos&1) win=1;
					}
					if (a[i]<=A+2*B-2)
					{
						if (pos%2==0) win=1;
					}
					if (a[i]>=A+A+A)
					{
						if (pos%2==0) win=1;
					}
				}
			}
			if (win) printf("YES\n");
			else printf("NO\n"); 
		}
	}
	return 0;
}