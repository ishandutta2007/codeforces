#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=100010;

int n,m;
long double a,b;
pair<long double,int> ay[MaxN],by[MaxN];
int l[MaxN];
long double most=1e20;
int ca,cb;

long double getdis(long double x1,long double y1,long double x2,long double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void check(int i,int j)
{
	long double get=getdis(0,0,a,ay[i].first)+getdis(a,ay[i].first,b,by[j].first)+l[by[j].second];
	if (get<most)
	{
		most=get;
		ca=ay[i].second;
		cb=by[j].second;
	}
}

int main()
{
	cin>>n>>m>>a>>b;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		ay[i]=make_pair(x,i);
	}
	for (int i=1;i<=m;++i)
	{
		int x;
		scanf("%d",&x);
		by[i]=make_pair(x,i);
	}
	for (int i=1;i<=m;++i)
		scanf("%d",&l[i]);
	sort(ay+1,ay+n+1);
	sort(by+1,by+m+1);
	for (int i=1;i<=m;++i)
	{
		long double d=a*by[i].first/b;
		int t=lower_bound(ay+1,ay+n+1,make_pair(d,0))-ay;
		if (t<=n) check(t,i);
		if (t>1) check(t-1,i);
	}
	cout<<ca<<" "<<cb<<endl;
	return 0;
}