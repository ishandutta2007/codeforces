#include<cstdio>
using namespace std;
int T,N;
bool iss[10101];
main()
{
	for(int i=1;i<=100;i++)iss[i*i]=true;
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		bool fn=false;
		for(;N--;)
		{
			int A;scanf("%d",&A);
			if(!iss[A])fn=true;
		}
		puts(fn?"YES":"NO");
	}
}