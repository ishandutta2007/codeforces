#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,lst,cr,all,tt;
pair<int,string> ans[3333];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if (k>4*n*m-2*n-2*m)
	{
		printf("NO\n");
		return 0;
	}
	if (m==1)
	{
		if (n==1)
		{
			printf("YES\n0\n");
			return 0;
		}
		if (k<n)
		{
			printf("YES\n1\n");
			printf("%d D\n",k);
		}
		else
		{
			printf("YES\n2\n");
			printf("%d D\n",n-1);
			k-=(n-1);
			printf("%d U\n",k);
		}
		return 0;
	}
	lst=k;
	for (int i=1;i<=n;i++)
	{
		if (i>1)
		{
			if (lst>=3*(m-1))
			{
				ans[++cnt]=make_pair(m-1,"RUD");
				lst-=(3*(m-1));
			}
			else
			{
				tt=lst/3;
				if (tt) ans[++cnt]=make_pair(tt,"RUD");
				lst%=3;
				if (lst==1)
				{
					ans[++cnt]=make_pair(1,"R");
				}
				else if (lst==2)
				{
					ans[++cnt]=make_pair(1,"RU");
				}
				lst=0;
			}
		}
		else
		{
			cr=min(lst,m-1);
			ans[++cnt]=make_pair(cr,"R");
			lst-=cr;
		}
		cr=min(lst,m-1);
		ans[++cnt]=make_pair(cr,"L");
		lst-=cr;
		if (i<n)
		{
			cr=min(lst,1);
			ans[++cnt]=make_pair(cr,"D");
			lst-=cr;
		}
	}
	cr=min(lst,n-1);
	ans[++cnt]=make_pair(cr,"U");
	all=cnt;
	for (int i=1;i<=cnt;i++)
	{
		if (ans[i].first==0)
		{
			all=i-1;
			break;
		}
	}
	printf("YES\n");
	printf("%d\n",all);
	for (int i=1;i<=all;i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}