#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,a[333333];
int st[333333],top,cur;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		top=0;
		for (int i=1;i<=n;i++)
		{
			cur=a[i];
			while(top && a[i]>st[top])
			{
				cur=st[top];
				top--;
			}
			st[++top]=cur;
		}
		if (top==1) printf("YES\n");
		else printf("NO\n");
	}
	return Accepted;
}