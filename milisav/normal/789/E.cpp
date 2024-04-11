#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int m=1500;
int n,k;
int s;
bool postoji[3000];
vector<int> a;
int p[3000];
int bfs()
{
	vector<int> q;
	p[m]=0;
	int ind=0;
	int u,v;
	q.push_back(m);
	while(ind<q.size())
	{
		u=q[ind];
		//if(ind==1) p[m]=1000000000;
		ind++;
		for(int i=0;i<a.size();i++)
		{
			v=u+a[i];
			//cout<<p[u]<<" "<<p[v]<<" "<<u-m<<" "<<v-m<<endl;
			if(abs(v-m)<=1000 && (p[u]+1<p[v] || v==m))
			{
				p[v]=p[u]+1;
				q.push_back(v);
				if(v==m) return p[v];
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&s);
		s=s-n;
		postoji[m+s]=true;
	}
	for(int i=0;i<=2600;i++)
	{
		p[i]=100000000;
		if(postoji[i]) a.push_back(i-m);
	}
	printf("%d",bfs());
	return 0;
}