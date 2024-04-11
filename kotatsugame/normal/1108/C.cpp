#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int N;
char S[2<<17];
main()
{
	scanf("%d%s",&N,S);
	string p="BGR";
	int ans=1e9;
	string ap;
	do{
		int now=0;
		for(int i=0;i<N;i++)now+=p[i%3]!=S[i];
		if(ans>now)ans=now,ap=p;
	}while(next_permutation(p.begin(),p.end()));
	printf("%d\n",ans);
	for(int i=0;i<N;i++)putchar(ap[i%3]);
	puts("");
}