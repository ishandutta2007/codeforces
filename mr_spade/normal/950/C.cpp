#include<cstdio>
#include<cstring>
#include<queue>
using std::queue;
const int L=2e5+5;
int n,cnt;
int next[L];
char s[L];
bool book[L];
queue<int> Q0,Q1;
signed main()
{
	register int i;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
		if(s[i]=='0')
		{
			if(Q1.size())
				next[Q1.front()]=i,Q1.pop();
			else
				cnt++;
			Q0.push(i);
		}
		else
		{
			if(Q0.size())
				next[Q0.front()]=i,Q0.pop();
			else
				return puts("-1"),0;
			Q1.push(i);
		}
	if(Q1.size())
		return puts("-1"),0;
	int now,ccnt;
	printf("%d\n",cnt);
	for(i=1;i<=n;i++)
		if(!book[i])
		{
			now=i;ccnt=0;
			do
			{
				ccnt++;
			}while(now=next[now]);
			printf("%d ",ccnt);
			now=i;
			do
			{
				book[now]=1;
				printf("%d ",now);
			}while(now=next[now]);
			putchar('\n');
		}
	return 0;
}