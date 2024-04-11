#include<iostream>
#include<utility>
#include<algorithm>
#include<cstdio>
using namespace std;
pair<int,pair<int,int> >a[1<<20];
int n,N=1,myleft;
int width[1<<20];
int p[1<<20],myrank[1<<20];
int find(int a){return p[a]-a?p[a]=find(p[a]):a;}
void unite(int a,int b)
{
	int pa=find(a),pb=find(b);
	if(pa!=pb)
	{
		if(myrank[pa]>myrank[pb])
		{
			p[pb]=pa;
		}
		else
		{
			p[pa]=pb;
			if(myrank[pa]==myrank[pb])myrank[pb]++;
		}
	}
}
bool same(int a,int b)
{
	return find(a)==find(b);
}
pair<int,pair<int,int> >d(int k)
{
	int l=2*k+1,f=2*k+2;
	return make_pair(a[l].first+a[f].first
			+(a[l].second.second&&a[f].second.first)
			-(a[l].second.second==0&&a[f].second.first==0),
			make_pair(
				a[l].second.first+(a[l].second.first==width[l]?
					a[f].second.first:0),
				a[f].second.second+(a[f].second.second==width[f]?
					a[l].second.second:0)
				)
			);
}
void make()
{
	while(N<n+1)N*=2;
	int pre=0,divide=1;
	for(int i=0;i<=2*N-2;i=i*2+2)
	{
		for(int j=pre;j<=i;j++)width[j]=N/divide;
		pre=i+1;divide*=2;
	}
	for(int i=0;i<N;i++)a[i+N-1]=make_pair(i<=n,make_pair(i>n,i>n));
	for(int i=N-2;i>=0;i--)a[i]=d(i);
	for(int i=0;i<2*N-2;i++)myrank[i]=0,p[i]=i;
	myleft=n+1;
}
void f(int k)
{
	unite(k,N-1);
	k+=N-1;a[k]=make_pair(0,make_pair(1,1));
	while(k>0)
	{
		k=(k-1)/2;
		a[k]=d(k);
	}
}
int c()
{
	while(same(myleft-1,N-1))myleft--;
	return a[0].first-(N-1-myleft);
}
main()
{
	cin>>n;make();
	printf("%d ",c());
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		f(p);
		printf("%d%c",c(),i==n-1?10:32);
	}
}