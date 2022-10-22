#include <iostream>
#include <cstdio>
using namespace std;
int n,x;
int main()
{
	scanf("%d %d",&n,&x);
	if(x==0 && n%2==0) n--;
	if(x==2 && n%2==1) n--;
	if(n>0 && x!=1)
	{
		n--;
		x=1;
	}
	n=n%6;
	//cout<<n<<endl;
	while(n>0)
	{
		if(n%2==1)
		{
			if(x!=2) x=1-x;
		}
		else
		{
			if(x!=0) x=3-x;
		}
		//cout<<x<<endl;
		n--;
	}
	printf("%d",x);
	return 0;
}