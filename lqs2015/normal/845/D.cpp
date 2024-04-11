#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int cntc,n,tp,ans,x,curs;
stack<int> pq;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%d",&x);
			curs=x;
		}
		else if (tp==2)
		{
			ans+=cntc;
			cntc=0;
		}
		else if (tp==3)
		{
			scanf("%d",&x);
			pq.push(-x); 
		}
		else if (tp==4) cntc=0;
		else if (tp==5)
		{
			while(!pq.empty()) pq.pop();
		}
		else cntc++;
		while(!pq.empty() && -pq.top()<curs) 
		{
			ans++;
			pq.pop();
		}
	}
	printf("%d\n",ans);
	return 0;
}