#include<cstdio>
using namespace std;
int N;
char S[2<<17],T[2<<17];
int s[2<<17],t[2<<17],ans[2<<17];
main()
{
	scanf("%d%s%s",&N,S,T);
	for(int i=0;i<N;i++)
	{
		s[i]=S[i]-'a';
		t[i]=T[i]-'a';
	}
	for(int i=0;i<N;i++)
	{
		ans[i]=(s[i]+t[i])/2;
		if(s[i]+t[i]&1)t[i+1]+=26;
	}
	for(int i=N;--i;)
	{
		ans[i-1]+=ans[i]/26;
		ans[i]%=26;
	}
	for(int i=0;i<N;i++)putchar(ans[i]+'a');
	puts("");
}