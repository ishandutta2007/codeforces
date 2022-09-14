#include<cstdio>
using namespace std;
int N;
char S[2<<17];
char up[26];
int ans[2<<17];
main()
{
	scanf("%d%s",&N,S);
	int mx=0;
	for(int i=0;i<N;i++)
	{
		int id=0;
		while(up[id]>S[i])id++;
		up[id]=S[i];
		ans[i]=id;
		if(mx<id)mx=id;
	}
	if(mx>=2)puts("NO");
	else
	{
		puts("YES");
		for(int i=0;i<N;i++)printf("%d",ans[i]);
		puts("");
	}
}