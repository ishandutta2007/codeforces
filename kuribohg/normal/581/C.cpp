#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
const int MAXN=100010;
typedef pair<int,int> PII;
int n,k,a[MAXN],ans;
priority_queue<PII,vector<PII>,greater<PII> > q;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int x=(a[i]/10+1)*10;
		ans+=a[i]/10;
		if(a[i]==100) continue;
		q.push(make_pair(x-a[i],i));
	}
	while(!q.empty())
	{
		PII p=q.top();q.pop();
		if(k>=p.first)
		{
			k-=p.first,a[p.second]+=p.first,ans++;
			if(a[p.second]!=100) q.push(make_pair(10,p.second));
		}
		else break;
	}
	printf("%d\n",ans);
	return 0;
}