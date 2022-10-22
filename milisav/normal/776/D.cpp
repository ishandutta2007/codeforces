#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define lli long long int
using namespace std;

struct sijalica
{
	lli gori;
	vector<lli> prek;
};

lli n;lli m;
sijalica a[100001];
lli prekidaci[100001];
vector<lli> k[100001];
vector<bool> res;

bool sredi_prekidac(lli p)
{
	bool t=true;
	for (int i=0;i<k[p].size();i++)
	{
		lli s=k[p][i];
		lli drugi;
		if (a[s].prek[0]==p) drugi=1;
		else drugi=0;
		if (a[s].gori==1) 
		{
			if (prekidaci[a[s].prek[drugi]]==-1)
			{
				prekidaci[a[s].prek[drugi]]=prekidaci[p];
				t=t&&sredi_prekidac(a[s].prek[drugi]);
			}
			else if (prekidaci[a[s].prek[drugi]]==prekidaci[p]) t=t&&true;
			else t=t&&false;	
		}
		else
		{
			if (prekidaci[a[s].prek[drugi]]==-1)
			{
				prekidaci[a[s].prek[drugi]]=1-prekidaci[p];
				t=t&&sredi_prekidac(a[s].prek[drugi]);
			}
			else if (prekidaci[a[s].prek[drugi]]!=prekidaci[p]) t=t&&true;
			else t=t&&false;	
		} 
	}
	return t;
}

int main()
{
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].gori);
	}
	memset(prekidaci,-1,sizeof(prekidaci));
	for (int i=1;i<=m;i++)
	{
		lli pom;
		scanf("%lld",&pom);
		for (int j=0;j<pom;j++)
		{
			lli b;
			scanf("%lld",&b);
			k[i].push_back(b);
			a[b].prek.push_back(i);
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (prekidaci[i]==-1)
		{
			prekidaci[i]=0;
			bool f1=sredi_prekidac(i);
			//memset(prekidaci,-1,sizeof(prekidaci));
			//prekidaci[i]=1;
			//bool f2=sredi_prekidac(i);
			res.push_back(f1);
		}
	}
	bool ans=true;
	for (int i=0;i<res.size();i++)
	{
		ans=ans&&res[i];
	}
	if (ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}