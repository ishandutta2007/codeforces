#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,K;
char s[2<<17];
int cnt[26];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d\n%s",&N,&K,s);
		int ans=0;
		for(int i=0;i<=K-i-1;i++)
		{
			for(int j=0;j<26;j++)cnt[j]=0;
			for(int j=0;j<N;j+=K)
			{
				cnt[s[j+i]-'a']++;
				if(i<K-i-1)cnt[s[j+(K-i-1)]-'a']++;
			}
			int nm=0;
			for(int j=0;j<26;j++)
			{
				ans+=cnt[j];
				if(nm<cnt[j])nm=cnt[j];
			}
			ans-=nm;
		}
		printf("%d\n",ans);
	}
}