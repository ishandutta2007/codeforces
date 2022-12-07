#include<bits/stdc++.h>

using namespace std;

int x,y,n,a,b;

int main()
{
	a=b=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		if(x==y)continue;
		if(x>y)a++;
		if(x<y)b++;
	}
	if(a>b)printf("Mishka");
	else if(a<b)printf("Chris");
	else printf("Friendship is magic!^^");
	return 0;
}