#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;){
		scanf("%d",&N);
		if(N==1)puts("0");
		else if(N==2)puts("1");
		else if(N==3)puts("2");
		else if(N%2==0)puts("2");
		else puts("3");
	}
}