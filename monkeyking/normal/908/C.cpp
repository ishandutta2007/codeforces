#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>
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
#define pii pair<double,double>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
double n,r;
double a[1005];
pii c[1005];
//
//bool cd(pii a,pii b)
//{
////	if(a.second>=b.second && a.second<=r+b.second) return true;
////	if(b.second<=a.second && b.second<=r+a.second) return true;
////cout<<a.second<<' '<<b.second<<endl;
//	if(abs(a.first-b.first)<=r) return true;
////	if(a.second+r>=b.second && a.second<b.second) return true;
////	if(b.second+r>=a.second && b.second<a.second) return true;
//	return false;
//}

void maxas(double &a,const double &b)
{
	if(b>a) a=b;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>r;
	rep(n)
	{
		cin>>a[i];
	}
	bool f;
	double tx,ty=(r*2)*(r*2),ans;
	for(int i=0;i<n;i++)
	{
		f=true;
		for(int j=i-1;j>=0;j--)
		{
//			cout<<j<<endl; 
			if(abs(a[i]-a[j])<=r*2)
			{
				f=false;
				tx=(a[i]-a[j])*(a[i]-a[j]);
//				cout<<a[i]<<' '<<a[j]<<Endl;
//				cout<<a[i]<<' '<<a[j]<<' '<<ty-tx<<Endl;
				ans=sqrt(ty-tx);
//				cout<<ans+c[j].second<<endl;
				c[i].first=a[i];
				maxas(c[i].second,ans+c[j].second);
			}
		}
		if(f)
		{
			c[i].first=a[i];
			c[i].second=r;
//			cout<<r<<endl;
		}
		cout.precision(10);
		cout<<c[i].second<<' ';
	}
	return 0;
}