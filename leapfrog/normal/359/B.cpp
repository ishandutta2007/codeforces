//
//
#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) if(k) printf("%d %d ",i<<1,(i<<1)-1),--k;else printf("%d %d ",(i<<1)-1,i<<1);
	return putchar('\n'),0;
}