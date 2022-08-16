#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int getabs(int x)
{
	return (x>=0)?x:-x;
}

const int MaxN=1010;

int n,m;
char s[MaxN][MaxN];
long double F[MaxN][MaxN];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			F[i][j]=F[i-1][j-1]+(i-1)*(j-1)*2+i*(i-1)/2+j*(j-1)/2;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			F[i][j]-=i*(i-1)/2+j*(j-1)/2;
}

int p;
vector<pair<int,int> > v;
long double ans;

void calc()
{
	for (int i=0;i<p;++i)
	{
		int get=m-v[i].second;
		for (int j=i-1;j>=0;--j)
		{
			if (v[j+1].first!=v[j].first+1) break;
			if (v[j].second<v[j+1].second) break;
			get+=m-v[j].second;
		}
		for (int j=i+1;j<p;++j)
		{
			if (v[j-1].first!=v[j].first-1) break;
			if (v[j].second<v[j-1].second) break;
			get+=m-v[j].second;
		}
		ans+=4.0*get*(v[i].second-1);
	}
}

void work()
{
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			long double tmp=F[i][j]+F[i][m-j+1]+F[n-i+1][j]+F[n-i+1][m-j+1]+i*(i-1)/2+j*(j-1)/2+(n-i+1)*(n-i)/2+(m-j+1)*(m-j)/2;
			if (s[i][j]=='.')
				ans+=tmp;
			else
			{
				ans-=tmp;
				v.push_back(make_pair(i,j));
			}
		}
	p=v.size();
	for (int i=0;i<p;++i)
		for (int j=i+1;j<p;++j)
			ans+=(getabs(v[i].first-v[j].first)+getabs(v[i].second-v[j].second))*2;
	sort(v.begin(),v.end());
	calc();
	for (int i=0;i<p;++i)
		swap(v[i].first,v[i].second);
	swap(n,m);
	sort(v.begin(),v.end());
	calc();
	printf("%.10lf\n",(double)(ans/(n*m-p)/(n*m-p)));
}

int main()
{
	init();
	work();
	return 0;
}