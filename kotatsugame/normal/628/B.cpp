#include<cstdio>
#include<cstring>
using namespace std;
char S[3<<17];
main()
{
	scanf("%s",S);
	int N=strlen(S);
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		if(S[i]%4==0)ans++;
		if(i)
		{
			int n=(S[i-1]-'0')*10+S[i]-'0';
			if(n%4==0)ans+=i;
		}
	}
	printf("%lld\n",ans);
}