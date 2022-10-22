#include<bits/stdc++.h>
using namespace std;
const int N=300000;
const int INF=1e9;
int n,m;
char w;
vector<int> a[N+5],b[N+5],c[N+5];
int calc(char w)
{
	if(w=='A') return 1;
	if(w=='G') return 2;
	if(w=='C') return 3;
	if(w=='T') return 4;
}
void output(int w)
{
	if(w==1) printf("A");
	if(w==2) printf("G");
	if(w==3) printf("C");
	if(w==4) printf("T");
	return;
}
int checkcalc(vector<int> x,int ca,int cb)
{
	int sum=0;
	for(int i=0;i<x.size();i++)
	{
		if(i%2==0) if(x[i]!=ca) sum++;
		if(i%2==1) if(x[i]!=cb) sum++;
	}
	return sum;
}
vector<int> copyvector(int ca,int cb,int len)
{
	vector<int> v;
	for(int i=0;i<len;i++)
	{
		if(i%2==0) v.push_back(ca);
		if(i%2==1) v.push_back(cb);
	}
	return v;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>w;
			a[i].push_back(calc(w));
			b[j].push_back(calc(w));
		}
	}
	int ans=INF,num[4],vis[4],flag;
	num[0]=1,num[1]=2,num[2]=3,num[3]=4;
	do
	{
		int i=num[0],j=num[1],k=num[2],s=num[3];
		int temp=0;
		for(int p=1;p<=n;p++)
		{
			if(p%2==1) temp+=min(checkcalc(a[p],i,j),checkcalc(a[p],j,i));
			else temp+=min(checkcalc(a[p],k,s),checkcalc(a[p],s,k));
		}
		if(ans>temp)
		{
			flag=0;
			ans=temp;
			for(int p=0;p<=3;p++) vis[p]=num[p];
		}
				
	}
	while(next_permutation(num,num+4));
	num[0]=1,num[1]=2,num[2]=3,num[3]=4;
	do
	{
		int i=num[0],j=num[1],k=num[2],s=num[3];
		int temp=0;
		for(int p=1;p<=m;p++)
		{
			if(p%2==1) temp+=min(checkcalc(b[p],i,j),checkcalc(b[p],j,i));
			else temp+=min(checkcalc(b[p],k,s),checkcalc(b[p],s,k));
		}
		if(ans>temp)
		{
			flag=1;
			ans=temp;
			for(int p=0;p<=3;p++) vis[p]=num[p];
		}		
	}
	while(next_permutation(num,num+4));
	if(!flag)
	{
		for(int i=1;i<=n;i++)
		{
			int now=0;
			if(i%2==0) now=2; 
			int cnta=checkcalc(a[i],vis[0+now],vis[1+now]);
			int cntb=checkcalc(a[i],vis[1+now],vis[0+now]);
			if(cnta>cntb) c[i]=copyvector(vis[1+now],vis[0+now],m);
			else c[i]=copyvector(vis[0+now],vis[1+now],m);
		}
		for(int i=1;i<=n;i++) 
		{
			for(int j=0;j<m;j++)
			{
				output(c[i][j]);
			}
			printf("\n");
		}	
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			int now=0;
			if(i%2==0)now=2; 
			int cnta=checkcalc(b[i],vis[0+now],vis[1+now]);
			int cntb=checkcalc(b[i],vis[1+now],vis[0+now]);
			if(cnta>cntb) c[i]=copyvector(vis[1+now],vis[0+now],n);
			else c[i]=copyvector(vis[0+now],vis[1+now],n);
		}	
		for(int i=0;i<n;i++) 
		{
			for(int j=1;j<=m;j++)
			{
				output(c[j][i]);
			}
			printf("\n");
		}	
	}
	return 0;
}