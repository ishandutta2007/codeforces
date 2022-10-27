#include <bits/stdc++.h>
using namespace std;
int n,m;
int in1[300300];
int in2[300300];
vector <int> G1[300010];
vector <int> G2[300010];
int s[300300];
void tuopu1(){
	queue <int>	que;
	int res=n;
	for(int i=1;i<=n;i++)
	{
		if(in1[i]==0)
		{
			que.push(i);
			res--;
		}
	}
	while(!que.empty())
	{
		int t=que.front();
		que.pop();
		if(que.size()==0)
		{
			s[t]+=res;
		}
		if(que.size()==1)
		{
			int tt=que.front();
			int flag=1;
			for(int i=0;i<G1[tt].size();i++)
			{
				int c=G1[tt][i];
				if(in1[c]==1)
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				s[t]+=res;
			}
		}
		for(int i=0;i<G1[t].size();i++)
		{
			if(--in1[G1[t][i]]==0)
			{
				res--;
				que.push(G1[t][i]);
			}
		}
	}
}
void tuopu2(){
	queue <int>	que;
	int res=n;
	for(int i=1;i<=n;i++)
	{
		if(in2[i]==0)
		{
			que.push(i);
			res--;
		}
	}
	while(!que.empty())
	{
		int t=que.front();
		que.pop();
		if(que.size()==0)
		{
			s[t]+=res;
		}
		if(que.size()==1)
		{
			int tt=que.front();
			int flag=1;
			for(int i=0;i<G2[tt].size();i++)
			{
				int c=G2[tt][i];
				if(in2[c]==1)
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				s[t]+=res;
			}
		}
		for(int i=0;i<G2[t].size();i++)
		{
			if(--in2[G2[t][i]]==0)	{
				res--;que.push(G2[t][i]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int v,u;
		scanf("%d%d",&v,&u);
		G1[u].push_back(v);
		G2[v].push_back(u);
		in1[v]++;
		in2[u]++;
	}
	tuopu1();
	tuopu2();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]+2>=n)	ans++;
	}
	printf("%d\n",ans);
	return 0;
}