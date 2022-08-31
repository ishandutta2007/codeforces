#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=100010;

int n,m,h,t;
vector<int> v[MaxN];
int used[MaxN];

bool check(int x,int y,int dx,int dy,int get)
{
	int nx=dx-get-t;
	int ny=dy-get-h;
	if (-nx-ny<=get&&dx>=t&&dy>=h)
	{
		puts("YES");
		printf("%d %d\n",y,x);
		int p=0;
		for (vector<int>::iterator it=v[y].begin();it!=v[y].end();++it)
			if (!used[*it]&&*it!=x)
			{
				++p;
				printf("%d ",*it);
				if (p==h) break;
			}
		if (p<h)
		for (vector<int>::iterator it=v[y].begin();it!=v[y].end();++it)
			if (used[*it]&&*it!=x)
			{
				++p;
				printf("%d ",*it);
				used[*it]=0;
				if (p==h) break;
			}
		puts("");
		p=0;
		for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
			if (used[*it]&&*it!=y)
			{
				++p;
				printf("%d ",*it);
				if (p==t) break;
			}
		puts("");
		return true;
	}
	nx=dx-get-h;
	ny=dy-get-t;
	if (-nx-ny<=get&&dx>=h&&dy>=t)
	{
		puts("YES");
		printf("%d %d\n",x,y);
		vector<int> g;
		int p=0;
		for (vector<int>::iterator it=v[y].begin();it!=v[y].end();++it)
			if (!used[*it]&&*it!=x)
			{
				++p;
				g.push_back(*it);
				if (p==t) break;
			}
		if (p<t)
		for (vector<int>::iterator it=v[y].begin();it!=v[y].end();++it)
			if (used[*it]&&*it!=x)
			{
				++p;
				g.push_back(*it);
				used[*it]=0;
				if (p==t) break;
			}
		p=0;
		for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
			if (used[*it]&&*it!=y)
			{
				++p;
				printf("%d ",*it);
				if (p==h) break;
			}
		puts("");
		for (int i=0;i<t;++i)
			printf("%d ",g[i]);
		puts("");
		return true;
	}
	return false;
}

int main()
{
	cin>>n>>m>>h>>t;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=n;++i)
	{
		int dx=v[i].size()-1;
		for (int k=0;k<v[i].size();++k)
			used[v[i][k]]=1;
		for (vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
		{
			int dy=v[*it].size()-1;
			if (dx>=h+t&&dy>=h+t)
			{
				puts("YES");
				memset(used,0,sizeof(used));
				printf("%d %d\n",i,*it);
				int get=0;
				for (int k=0;k<v[i].size();++k)
					if (v[i][k]!=*it)
					{
						++get;
						printf("%d ",v[i][k]);
						used[v[i][k]]=1;
						if (get==h) break;
					}
				puts("");
				get=0;
				for (int k=0;k<v[*it].size();++k)
					if (v[*it][k]!=i&&!used[v[*it][k]])
					{
						++get;
						printf("%d ",v[*it][k]);
						if (get==t) break;
					}
				puts("");
				return 0;
			}
			if (dy<h+t)
			{
				int get=0;
				for (int k=0;k<v[*it].size();++k)
					if (v[*it][k]!=i)
						if (used[v[*it][k]]) ++get;
				if (check(i,*it,dx,dy,get)) return 0;
			}
		}
		for (int k=0;k<v[i].size();++k)
			used[v[i][k]]=0;
	}
	puts("NO");
	return 0;
}