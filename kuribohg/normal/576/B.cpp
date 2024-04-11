#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=100010;
int n,p[MAXN],id[MAXN],tot;
vector<int> v[MAXN];
bool used[MAXN];
bool cmp(int i,int j)
{
	return v[i].size()<v[j].size();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
	{
		if(used[i]) continue;
		int x=i;
		v[++tot].push_back(x);
		used[x]=true;
		while(!used[p[x]])
		{
			x=p[x],used[x]=true;
			v[tot].push_back(x);
		}
	}
	for(int i=1;i<=tot;i++) id[i]=i;
	sort(id+1,id+tot+1,cmp);
	if(v[id[1]].size()==1)
	{
		puts("YES");
		int x=v[id[1]][0];
		for(int i=1;i<=n;i++)
			if(i!=x) printf("%d %d\n",i,x);
	}
	else if(v[id[1]].size()==2)
	{
		for(int i=2;i<=tot;i++)
			if((int)(v[id[i]].size())&1) {puts("NO");return 0;}
		puts("YES");
		for(int i=2;i<=tot;i++)
			for(int j=0;j<v[id[i]].size();j++)
				printf("%d %d\n",v[id[1]][j&1],v[id[i]][j]);
		printf("%d %d\n",v[id[1]][0],v[id[1]][1]);
	}
	else puts("NO");
	return 0;
}