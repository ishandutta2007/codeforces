#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=110;
const long double ZERO=1e-10;

long double getabs(long double x)
{
	return (x>=0)?x:-x;
}

int n,s;
int d[MaxN];
int v[MaxN][MaxN],x[MaxN][MaxN],pt[MaxN][MaxN];
vector<int> p;
long double t[MaxN][MaxN*MaxN];
int pv[MaxN][MaxN*MaxN][2];

int main()
{
	cin>>n>>s;
	for (int i=1;i<=n;++i)
	{
		cin>>d[i];
		for (int j=1;j<=d[i];++j)
		{
			int t;
			cin>>v[i][j]>>t;
			x[i][j]=x[i][j-1]+v[i][j]*t;
			pt[i][j]=pt[i][j-1]+t;
			p.push_back(x[i][j]);
		}
	}
	p.push_back(0);
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	for (int i=1;i<=n;++i)
		for (int k=1,j=1;k<p.size();++k)
		{
			t[i][k]=t[i][k-1]+(long double)(p[k]-p[k-1])/v[i][j];
			pv[i][k][0]=pv[i][k][1]=v[i][j];
			if (p[k]==x[i][j])
			{
				t[i][k]=pt[i][j];
				++j;
				pv[i][k][1]=v[i][j];
			}
		}
	int ans=0;
	for (int k=1;k<p.size();++k)
	{
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j) if (i!=j)
				if (t[i][k-1]+ZERO<t[j][k-1]&&t[i][k]>t[j][k]+ZERO)
					++ans;
				else if (p[k]!=s) if (getabs(t[i][k]-t[j][k])<=ZERO&&pv[i][k][0]>pv[j][k][0]&&pv[i][k][1]>pv[j][k][1])
					++ans;
	}
	cout<<ans<<endl;
	return 0;
}