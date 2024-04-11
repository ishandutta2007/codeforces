#include<bits/stdc++.h>
using namespace std;

int n,x;
bool f;

int main()
{
	f=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x%2==0) printf("%d\n",x/2);
		else
		{
			if(!f) 
			{
				if(x>=0) printf("%d\n",x/2);
				else printf("%d\n",(x-1)/2);
			}
			else if(x>=0) printf("%d\n",(x+1)/2);
			else printf("%d\n",x/2);
			f^=1;
		}
	}
	return 0;
}