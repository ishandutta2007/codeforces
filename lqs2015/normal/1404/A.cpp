#include<bits/stdc++.h>
using namespace std;
int test,n,k,a,b,con[333333];
bool flg;
char s[333333];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s);
		for (int i=0;i<k;i++) con[i]=0;
		flg=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='0')
			{
				if (con[i%k]==2) flg=1;
				con[i%k]=1;
			}
			else if (s[i]=='1')
			{
				if (con[i%k]==1) flg=1;
				con[i%k]=2;
			}
		}
		a=b=0;
		for (int i=0;i<k;i++)
		{
			if (con[i]==1) a++;
			if (con[i]==2) b++;
		}
		if (a>k/2 || b>k/2) flg=1;
		if (flg) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}