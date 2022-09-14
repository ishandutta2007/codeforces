#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
long long ans=1,mod=1e9+7;
int n;
char s[99];
main()
{
	scanf("%d",&n);
	priority_queue<int>P;
	priority_queue<int,vector<int>,greater<int> >Q;
	P.push(-1e9);
	Q.push(1e9);
	queue<int>tmp;
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%s %d",s,&p);
		if(s[1]=='D')
		{
			if(P.top()<p&&p<Q.top())
			{
				tmp.push(p);
			}
			else if(p<P.top())
			{
				P.push(p);
			}
			else if(p>Q.top())
			{
				Q.push(p);
			}
		}
		else
		{
			while(!tmp.empty())
			{
				int q=tmp.front();
				tmp.pop();
				if(p==q)continue;
				else if(p>q)P.push(q);
				else if(p<q)Q.push(q);
			}
			if(P.top()<p&&p<Q.top())
			{
				ans=ans*2%mod;
			}
			else if(P.top()==p)
			{
				P.pop();
			}
			else if(Q.top()==p)
			{
				Q.pop();
			}
			else
			{
				printf("0\n");
				return 0;
			}
		}
	}
	ans*=tmp.size()+1;
	ans%=mod;
	printf("%lld\n",ans);
}