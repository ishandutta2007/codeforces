#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<queue>
using namespace std;
int n,tot,x;
char str[10];
pair<int,int> P[1000010];
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		if(str[0]!='r') scanf("%d",&x);
		if(str[0]=='i') q.push(x),P[++tot]=make_pair(1,x);
		else if(str[0]=='r')
		{
			if(q.empty()) P[++tot]=make_pair(1,1),q.push(1);
			q.pop(),P[++tot]=make_pair(2,0);
		}
		else
		{
			while(!q.empty()&&q.top()<x) q.pop(),P[++tot]=make_pair(2,0);
			if(q.empty()||q.top()!=x) q.push(x),P[++tot]=make_pair(1,x);
			P[++tot]=make_pair(3,x);
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
	{
		if(P[i].first==1) printf("insert %d\n",P[i].second);
		else if(P[i].first==2) puts("removeMin");
		else printf("getMin %d\n",P[i].second);
	}
	return 0;
}