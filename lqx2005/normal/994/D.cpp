#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=60;
struct node
{
	int a,b;
}t[N+5],s[N+5];
int check(node a,node b)
{
	if((a.a==b.a&&a.b==b.b)||(a.b==b.a&a.a==b.b)) return 0;
	if(a.a==b.a) return a.a;
	if(a.a==b.b) return a.a;
	if(a.b==b.a) return a.b;
	if(a.b==b.b) return a.b;
	return 0;
}
int n,m;
int bucket[N+5];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&t[i].a,&t[i].b);
	for(int i=1;i<=m;i++) scanf("%d%d",&s[i].a,&s[i].b);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!check(t[i],s[j])) continue;
			int now=check(t[i],s[j]);
			bool cal=0;
			for(int k=1;k<=n;k++)
			{
				for(int r=1;r<=m;r++)
				{
					if(k==i&&r==j) continue;
					if(!check(t[k],s[r])) continue;
					int nxt=check(t[k],s[r]);
					if(nxt!=now) cal=1;			
				}
			}
			if(!cal) 
			{
				printf("%d\n",now);
				return 0;
			}
		}
	}
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!check(t[i],s[j])) continue;
			int now=check(t[i],s[j]);
			for(int k=1;k<=m;k++)
			{
				if(!check(t[i],s[k])) continue;
				int nxt=check(t[i],s[k]);
				if(nxt!=now) flag=1;
			}
			for(int k=1;k<=n;k++)
			{
				if(!check(t[k],s[j])) continue;
				int nxt=check(t[k],s[j]);
				if(nxt!=now) flag=1;
			}
		}
	}
	if(flag) printf("-1\n");
	else printf("0\n");
	return 0;
}