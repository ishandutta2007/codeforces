#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int l[100005];
int main()
{
	int q;
	scanf("%d",&q);
	memset(l,-1,sizeof(l));
	for (int x=0;x<q;x++)
	{
	    int n,y,ans=0;
	    scanf("%d%d",&n,&y);
	    for (int i=1;i*i<=n;i++)
	    {
	        if (n%i==0)
	        {
	            ans+=(l[i]<x-y);
	            l[i]=x;
	            ans+=(l[n/i]<x-y);
	            l[n/i]=x;
	        }
	    }
	    printf("%d\n",ans);
	}
}