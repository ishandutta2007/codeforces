#include <iostream>
using namespace std;
int main()
{
	int n,m,len=1e9,l;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		if (b-a<len)
		{
			len=b-a;
			l=a;
		}
	}
	printf("%d\n",len);
	for (int i=0;i<n;i++)
	printf("%d ",(i-l+1LL*n*len)%len);
}