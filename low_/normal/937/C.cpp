#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005

const double eps=1e-40;
double interval;

int CNP(int l, int r)
{
	if (l*interval>1) return l-1;
	if ((r*interval-1)<eps) return r;
	int mid=(l+r)/2;
	
	if (mid*interval-1<eps) return CNP(mid+1, r);
	else return CNP(l, mid);
}

main()
{
	int k, d, t;
	cin>>k>>d>>t;
	int itvl=(k/d)*d; // thoi gian cua 1 interval
	if (k%d>0) itvl+=d;
	cerr<<itvl<<"\n";
	interval=(double)(k+itvl)/(double)(2*t); // ty le con ga duoc nau 
	
	cerr<<interval<<"\n";
	int c=CNP(1, 1e18); // so lan interval
	cerr<<c<<"\n";
	double ans=c*itvl;
	double temp=(double)1-(double)c*(double)interval;
	cerr<<ans<<" "<<temp<<"\n";
	if (temp-(double)k/(double)t<eps) ans+=(double)temp*(double)t;
	else ans+=(double)k+(double)(temp-k/(double)t)*(double)(2*t);
	
	printf("%0.9f", ans);
}