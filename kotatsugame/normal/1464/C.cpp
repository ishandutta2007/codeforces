#include<cstdio>
using namespace std;
int N;
long long T;
int cnt[1<<17];
char S[1<<17];
main()
{
	scanf("%d%lld\n%s",&N,&T,S);
	T-=1<<S[N-1]-'a';
	T+=1<<S[N-2]-'a';
	N-=2;
	for(int i=0;i<N;i++)cnt[S[i]-'a']++;
	for(int i=26;i--;)while(cnt[i]--)
	{
		if(T>0)T-=1<<i;
		else T+=1<<i;
	}
	puts(T?"No":"Yes");
}