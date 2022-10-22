#include<bits/stdc++.h>
using namespace std;
int t,a,b,c;
int main()
{
	scanf("%d",&t);
	for(int tot=1;tot<=t;tot++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a<b) swap(a,b);
		if(a<c) swap(a,c);
		if(b+c+1>=a) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}