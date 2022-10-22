#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[100010],s[100010];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
priority_queue<int> pq,dl,tp;
int gt()
{
	while (!dl.empty() && dl.top()==pq.top()) dl.pop(),pq.pop();
	if (pq.empty()) return -1;return pq.top();
}
int main()
{
	int n,d,i,t=0;cin>>n>>d;
	for (i=1;i<=n;i++) f[i]=i,s[i]=1,pq.push(1);
	for (i=1;i<=d;i++)
	{
		int u,v,t1,t2;cin>>u>>v;
		t1=find(u);t2=find(v);
		if (t1==t2) t++;
		else
		{
			f[t1]=t2;dl.push(s[t1]);dl.push(s[t2]);
			s[t2]+=s[t1];pq.push(s[t2]);
		}
		int res=-1;
		for (int j=0;j<=t;j++)
		{
			int u=gt();if (u==-1) break;
			res+=u;pq.pop();tp.push(u);
		}
		while (!tp.empty()) pq.push(tp.top()),tp.pop();
		cout<<res<<endl;
	}
}