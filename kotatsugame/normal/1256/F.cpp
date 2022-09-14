#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int Q,N;
char S[2<<17],T[2<<17];
long long calc(char s[])
{
	int N=strlen(s);
	int cnt[26]={};
	long long ret=0;
	for(int i=0;i<N;i++)
	{
		int t=s[i]-'a';
		for(int j=0;j<t;j++)ret+=cnt[j];
		cnt[t]++;
	}
	sort(s,s+N);
	return ret;
}
main()
{
	scanf("%d",&Q);
	for(;Q--;)
	{
		scanf("%d%s%s",&N,S,T);
		long long A=calc(S);
		long long B=calc(T);
		if(strcmp(S,T))puts("NO");
		else if(A%2!=B%2)
		{
			bool fn=false;
			for(int i=0;i+1<N;i++)if(S[i]==S[i+1])fn=true;
			puts(fn?"YES":"NO");
		}
		else puts("YES");
	}
}