#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,a[111111],pos,r,cur,rr;
bool can;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		can=1;
		pos=1;r=n;
		while(pos<=n)
		{
			cur=a[pos];rr=cur-1;
			pos++;
			while(pos<=n && cur<r)
			{
				if (a[pos]!=cur+1)
				{
					can=0;
					break;
				}
				cur++;pos++;
			}
			if (!can) break;
			r=rr;
		}
		if (!can) printf("No\n");
		else printf("Yes\n");
	}
	return Accepted;
}