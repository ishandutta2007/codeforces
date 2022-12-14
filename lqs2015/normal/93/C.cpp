#include<iostream>
#include<cstdio>
using namespace std;
int a[44],cur,ans[44],n;
string s[44];
bool f;
void dfs(int i,int des)
{
	if (a[i]>des) return;
	if (i>=cur) return;
	if (a[i]==des)
	{
		cur=i;
		for (int i=1;i<=cur;i++) ans[i]=a[i];
		return;
	}
	if (i>=6) return;
	for (int j=1;j<=i;j++)
	{
		for (int h=1;h<=8;h*=2)
		{
			if (i>=cur-1) return;
			a[i+1]=a[j]*h;
			dfs(i+1,des);
		}
	}
	for (int j=1;j<=i;j++)
	{
		for (int k=1;k<=i;k++)
		{
			for (int h=1;h<=8;h*=2)
			{
				if (i>=cur-1) return;
				a[i+1]=a[j]+a[k]*h;
				dfs(i+1,des);
			}
		}
	}
}
int main()
{
	cur=1e9;
	scanf("%d",&n);
	a[1]=1;
	dfs(1,n);
	printf("%d\n",cur-1);
	s[1]="eax";s[2]="ebx";s[3]="ecx";s[4]="edx";s[5]="eex";s[6]="efx";
	for (int i=2;i<=cur;i++)
	{
		cout<<"lea "<<s[i]<<", [";
		f=0;
		for (int j=1;j<i;j++)
		{
			for (int h=1;h<=8;h*=2)
			{
				if (ans[i]==ans[j]*h)
				{
					cout<<h<<"*"<<s[j]<<"]"<<endl;
					f=1;
					break;
				}
			}
			if (f) break;
		}
		if (f) continue;
		for (int j=1;j<i;j++)
		{
			for (int k=1;k<i;k++)
			{
				for (int h=1;h<=8;h*=2)
				{
					if (ans[k]*h+ans[j]==ans[i])
					{
						if (h==1) cout<<s[j]<<" + "<<s[k]<<"]"<<endl;
						else cout<<s[j]<<" + "<<h<<"*"<<s[k]<<"]"<<endl;
						f=1;
						break;
					}
				}
				if (f) break;
			}
			if (f) break;
		}
	}
	return 0;
}