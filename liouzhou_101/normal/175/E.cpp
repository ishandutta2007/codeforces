#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int nf,ne,ns;
double rf,re,rs,df,de;

void init()
{
	cin>>nf>>ne>>ns;
	cin>>rf>>re>>rs;
	cin>>df>>de;
	rf=sqrt(rf*rf-1);
	re=sqrt(re*re-1);
	rs=sqrt(rs*rs-1);
}

int v[30],w[30];
double ans;

double cross(double x1,double y1,double x2,double y2)
{
	return max(0.,min(y1,y2)-max(x1,x2));
}

void check()
{
	double get=nf*2*rf*df+ne*2*re*de;
	vector<double> p;
	for (int i=1;i<=nf+ne+ns;++i)
	{
		if (v[i]) continue;
		double gf=0,ge=0;
		for (int j=1;j<=ns;++j)
		{
			gf+=cross((i+1)/2-rf,(i+1)/2+rf,(w[j]+1)/2-rs,(w[j]+1)/2+rs)*df;
			ge+=cross((i+1)/2-re,(i+1)/2+re,(w[j]+1)/2-rs,(w[j]+1)/2+rs)*de;
		}
		get+=gf;
		p.push_back(ge-gf);
	}
	sort(p.rbegin(),p.rend());
	for (int i=0;i<ne;++i)
		get+=p[i];
	ans=max(ans,get);
}

void solve(int k,int s)
{
	if (k>nf+ne+ns)
	{
		if (!s) check();
		return;
	}
	v[k]=0;
	solve(k+1,s);
	if (s)
	{
		v[k]=1;
		w[s]=k;
		solve(k+1,s-1);
	}
}

void work()
{
	solve(1,ns);
	printf("%.10lf\n",ans);
}

int main()
{
	init();
	work();
	return 0;
}