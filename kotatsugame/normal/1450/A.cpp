#include<cstdio>
using namespace std;
int T,N;
char S[222];
int cnt[26];
char X[7]="bugyrt";
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d\n%s\n",&N,S);
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=0;i<N;i++)cnt[S[i]-'a']++;
		for(int i=0;i<6;i++)while(cnt[X[i]-'a']>0)
		{
			cnt[X[i]-'a']--;
			putchar(X[i]);
		}
		for(int i=0;i<26;i++)while(cnt[i]>0)
		{
			cnt[i]--;
			putchar(i+'a');
		}
		puts("");
	}
}