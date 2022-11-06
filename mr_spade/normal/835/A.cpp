#include<cstdio>
int s,v1,v2,t1,t2;
signed main()
{
	int i,j;
	scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
	if(s*v1+2*t1<s*v2+2*t2)
		puts("First");
	else if(s*v1+2*t1>s*v2+2*t2)
		puts("Second");
	else
		puts("Friendship");
	return 0;
}