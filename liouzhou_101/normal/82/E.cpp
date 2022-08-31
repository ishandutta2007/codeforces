#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=510;

int n;
double h,f;
vector<pair<double,double> > A,B;
double ans;

void init()
{
	cin>>n>>h>>f;
	for (int i=1;i<=n;++i)
	{
		double l,r;
		cin>>l>>r;
		if (l>=0)
			A.push_back(make_pair(l,r));
		else if (r<=0)
			B.push_back(make_pair(-r,-l));
		else
		{
			A.push_back(make_pair(0,r));
			B.push_back(make_pair(0,-l));
		}
		ans+=(r-l)*2*f/(f-h)*h*2;
	}
}

double calc(double px1,double px2)
{
	if (px1>px2) swap(px1,px2);
	double tx1=px1*(f+h)/(f-h);
	double tx2=px2*(f+h)/(f-h);
	if (tx1<=px2)
		return (px1+tx1)*h;
	double h0=(tx1-px2)*h*2/(tx1+tx2-px1-px2);
	return (px1+tx1)*h-(tx1-px2)*h0/2;
}

double solve(vector<pair<double,double> > &A)
{
	double get=0;
	for (int i=0;i<A.size();++i)
		for (int j=0;j<A.size();++j)
			get+=calc(A[i].first,A[j].first)+calc(A[i].second,A[j].second)-calc(A[i].first,A[j].second)-calc(A[i].second,A[j].first);
	return get;
}

int main()
{
	init();
	printf("%.10lf\n",ans-solve(A)-solve(B));
	return 0;
}