#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct disj
{
	int p;
	int v;
	int h;
};
int n,m,q;
vector<int> l[400000];
bool vis[400000];
int d[400000];
disj s[400000];
int findparent(int x)
{
	if(s[x].p!=x) s[x].p=findparent(s[x].p);
	return s[x].p;
}
void unitequery(int x,int y)
{
	int xp=findparent(x);
	int yp=findparent(y);
	if(xp!=yp)
	{
		int vx=s[xp].v;
		int vy=s[yp].v;
		int v=1;
		if(vx%2==1) v++;
		if(vy%2==1) v++;
		v+=vx/2;
		v+=vy/2;
		if(v<vx) v=vx;
		if(v<vy) v=vy;
		if(s[xp].h<s[yp].h)
		{
			s[xp].p=yp;
			s[yp].v=v;
		}
		else
		{
			s[yp].p=xp;
			if(s[xp].h==s[yp].h) s[xp].h++;
			s[xp].v=v;
		}
	}
}
void uniteordinary(int x,int y)
{
	int xp=findparent(x);
	int yp=findparent(y);
	if(s[xp].h<s[yp].h)
	{
		s[xp].p=yp;
	}
	else
	{
		s[yp].p=xp;
		if(s[xp].h==s[yp].h) s[xp].h++;
	}
}
void visit(int u)
{
	vector<int> q;
	d[u]=0;
	int v,w;
	q.push_back(u);
	int ind=0;
	while(ind<q.size())
	{
		v=q[ind];
		//cout<<v<<" "<<d[v]<<endl;
		vis[v]=true;
		for(int i=0;i<l[v].size();i++)
		{
			w=l[v][i];
			if(!vis[w])
			{
				d[w]=d[v]+1;
				q.push_back(w);
			}
		}
		ind++;
	}
	ind=0;
	int mi=u;
	while(ind<q.size()) 
	{
		if(d[q[ind]]>d[mi]) mi=q[ind];
		vis[q[ind]]=false;
		ind++;
	}
	q.clear();
	u=mi;
	//cout<<d[mi]<<endl;
	d[u]=0;
	v,w;
	q.push_back(u);
	ind=0;
	while(ind<q.size())
	{
		v=q[ind];
		vis[v]=true;
		for(int i=0;i<l[v].size();i++)
		{
			w=l[v][i];
			if(!vis[w])
			{
				d[w]=d[v]+1;
				q.push_back(w);
			}
		}
		ind++;
	}
	ind=0;
	mi=u;
	while(ind<q.size()) 
	{
		if(d[q[ind]]>d[mi]) mi=q[ind];
		ind++;
	}
	ind=0;
	while(ind<q.size()) 
	{
		//cout<<q[ind]<<" ";
		s[q[ind]].v=d[mi];
		ind++;
	}
	//cout<<endl;
	//cout<<d[mi]<<endl;
}
int main()
{
	int a,b,c;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
	{
		s[i].p=i;
		s[i].h=0;
		s[i].v=0;
		d[i]=-1;
		vis[i]=false;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		a--;
		b--;
		l[a].push_back(b);
		l[b].push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			visit(i);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<l[i].size();j++)
		{
			uniteordinary(i,l[i][j]);
		}
	}
	for(int i=0;i<q;i++)
	{
		scanf("%d",&c);
		if(c==2)
		{
			scanf("%d %d",&a,&b);
			a--;
			b--;
			unitequery(a,b);
		}
		else
		{
			scanf("%d",&a);
			a--;
			a=findparent(a);
			printf("%d\n",s[a].v);
		}
	}
	return 0;
}