#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
typedef unsigned long long ull;
const int inf=103974182;
const long double eps=1e-9;
using namespace std;
int n,k;
pair<long double,pair<long double,long double> > dp[1005][1600];
 
struct form
{
	int scoreSmall;
	int scoreLarge;
	int timeSmall;
	int timeLarge;
	long double probFail;
}a[1005];
 
inline bool equal(const long double &a,const long double &b)
{
	if(a-eps<=b && b<=a+eps) return true;
	if(b-eps<=a && a<=b+eps) return true;
	return false;
}
 
inline pair<long double,pair<long double,long double> > best(pair<long double,pair<long double,long double> > a,pair<long double,pair<long double,long double> > b)
{
	if(!equal(a.first,b.first))
	{
		if(a.first>b.first) return a;else return b;
	}
	if(a.second.first+a.second.second<b.second.first+b.second.second) return a;else return b;
}
 
//bool compare(const form &a,const form &b)
//{
//	if(equal(a.probFail*a.timeLarge,b.probFail*b.timeLarge)) return false;
//	return a.probFail*a.timeLarge<b.probFail*b.timeLarge;
//}
 
bool compare(form &a,form &b)
{
	return (b.probFail*(a.timeLarge*a.probFail+b.timeLarge)>a.probFail*(b.timeLarge*b.probFail+a.timeLarge));
}
 
int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].scoreSmall,&a[i].scoreLarge,&a[i].timeSmall,&a[i].timeLarge);
		cin>>a[i].probFail;
	}
	sort(a,a+n,compare);
	dp[0][0]={0,{0,0}};
	pair<long double,pair<long double,long double> >res={0,{0,0}};
	for(int i=0;i<n;i++)
	{
		for(int time=0;time<=k;time++)
		{
			dp[i+1][time]=best(dp[i+1][time],dp[i][time]);// 
			if(time+a[i].timeSmall<=k)// 
			{
				dp[i+1][time+a[i].timeSmall]=best(dp[i+1][time+a[i].timeSmall],mp(dp[i][time].first+a[i].scoreSmall,mp(dp[i][time].second.first+a[i].timeSmall,dp[i][time].second.second)));
			}
			if(time+a[i].timeLarge+a[i].timeSmall<=k)
			{
				dp[i+1][time+a[i].timeLarge+a[i].timeSmall]=best(dp[i+1][time+a[i].timeLarge+a[i].timeSmall],mp(dp[i][time].first+a[i].scoreSmall+a[i].scoreLarge*(1-a[i].probFail),mp(dp[i][time].second.first+a[i].timeSmall,dp[i][time].second.second*a[i].probFail+(1-a[i].probFail)*(time-dp[i][time].second.first+a[i].timeLarge))));
			}
		}
	}
	for(int i=0;i<=k;i++)
	{
		res=best(res,dp[n][i]);
	}
	cout.precision(15);
	cout<<res.first<<' '<<res.second.first+res.second.second<<endl;
	return 0;
}