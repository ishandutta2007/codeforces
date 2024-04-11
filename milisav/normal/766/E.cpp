#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int rt=0;
vector<int> a[200000];
int p[200000];
int b[200000];
int g[200000];
int h[200000];
int v[200000];
bool u[200000];
vector<int> t;
int n;
int x,y;
void bfs()
{
	vector<int> q;
	q.push_back(0);
	int ind=0;
	int m;
	while(ind<q.size())
	{
		m=q[ind];
		u[m]=true;
		for(int i=0;i<a[m].size();i++)
		{
			if(!u[a[m][i]])
			{
				//u[a[m][i]]=true;
				g[a[m][i]]=g[m]^v[a[m][i]];
				q.push_back(a[m][i]);
				p[a[m][i]]=m;
			}
		}
		ind++;
	}
}
void topo()
{
	b[0]=a[0].size();
	for(int i=1;i<n;i++)
	{
		b[i]=a[i].size()-1;
		if(b[i]==0) t.push_back(i);
	}
	int ind=0;
	int m;
	while(ind<t.size())
	{
		m=t[ind];
		if(m!=0)
		{
			b[p[m]]--;
			if(b[p[m]]==0) t.push_back(p[m]);
		}
		ind++;
	}
}
int main()
{
	scanf("%d",&n);
	long long int sum=0;
	int s1,s2;
	s1=0;
	s2=0;
	long long int r,d,e,f;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
		sum+=v[i];
	}
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&x,&y);
		x--;
		y--;
		a[x].push_back(y);
		a[y].push_back(x);
		u[i+1]=false;
	}
	g[0]=v[0];
	u[0]=false;
	bfs();
	topo();
	int l=1;
	int c;
	int k=0;
	long long int d1,d2,d3,d4;
	/*for(int i=0;i<n;i++) cout<<t[i]<<" ";
	cout<<endl;*/
	for(int i=0;i<n;i++) b[i]=1;
	for(int i=0;i<n-1;i++) b[p[t[i]]]+=b[t[i]];
	while(k<=20)
	{
		for(int i=0;i<n;i++)
		{
			if((g[i]&l)==l) h[i]=1;
			else h[i]=0;
		}
		for(int i=0;i<n-1;i++) h[p[t[i]]]+=h[t[i]];
		/*for(int i=0;i<n;i++)
		{
			//cout<<h[i]<<" "<<b[i]-h[i]<<" "<<b[i]<<endl;
		}*/
		s1=h[0];
		if((g[0]&l)==l) s1++;
		s2=n-s1;
		r=l;
		d=0;
		for(int i=0;i<n;i++)
		{
			f=0;
			e=0;
			c=((g[i]^v[i])&l);
			if(c>0) f+=(b[i]-h[i]);
			else f+=h[i];
			//cout<<f<<endl;
			c=(v[i]&l);
			if(c>0) f--;
			d1=h[i];
			d2=b[i]-h[i];
			for(int j=0;j<a[i].size();j++)
			{
				if(p[i]!=a[i][j])
				{
					d3=h[a[i][j]];
					d4=b[a[i][j]]-h[a[i][j]];
					if(c>0) e+=(d3*(d1-d3)+d4*(d2-d4));
					else e+=(d3*(d2-d4)+d4*(d1-d3));
					//cout<<i<<" "<<c<<" "<<d<<" "<<d3<<" "<<d1-d3<<" "<<d4<<" "<<d2-d4<<endl;
				}
			}
			e=e-f;
			e=e/2;
			f=f+e;
			d+=f;
		}
		r=d*r;
		//cout<<r<<endl;
		sum+=r;
		k++;
		l=(l<<1);
	}
	cout<<sum<<endl;
	return 0;
}