#include<bits/stdc++.h>
#define re register
int main()
{
	re int T,p1,p2,k;
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&p1,&p2,&k);
		if(p1>p2)std::swap(p1,p2);
		re int k1=p2/p1;
		if(p2%p1==0)k1--;
		else if(p1%(p2%p1)!=0)k1++;
		if(k1<k)puts("OBEY");else puts("REBEL");
	}
}