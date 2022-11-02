# include <iostream>
# include <cstdio>
using namespace std;


int a,b,n;
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	int t=(b-(a*10%b))%b;
	if(t<10)
	{
		printf("%d%d",a,t);
		--n;while(n--)printf("0");
	}
	else printf("-1\n");
	return 0;
}