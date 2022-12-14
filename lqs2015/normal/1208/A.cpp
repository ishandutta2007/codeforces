#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,a,b;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&a,&b,&n);
		if (n%3==0) printf("%d\n",a);
		else if (n%3==1) printf("%d\n",b);
		else printf("%d\n",a^b);
	}
	return Accepted;
}