#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 1100;
const double eps = 1e-10;

double f[maxn][maxn];
bool v[maxn][maxn];
int n,m;

double cal(double k1,double b1,double k2,double b2)
{
	if(b1-b2>eps) swap(k1,k2),swap(b1,b2);
	if(fabs(k1-k2)<eps||(k1+b1)-(k2+b2)<-eps) return b2+k2>0?k2:0;
	return (b2-b1)/(k1-k2)*k1+b1;
}
double solve(int n,int m)
{
	if(v[n][m]) return f[n][m];
	v[n][m]=true;
	if(!n||!m)
	{
		if(!n) f[n][m]=1.0/(m+1);
		else if(!m) f[n][m]=1.0;
		return f[n][m];
	}
	double f1=solve(m-1,n),f2=solve(m,n-1),m1=m+1.0,mm1=(double)m/m1;
	f[n][m]=cal((1.0-f1)*mm1-1,1,1.0/m1+mm1*(1.0-f1)-(1.0-f2),1.0-f2);
	double tmp=1.0/m1;
	if(f[n][m]-tmp<-eps) f[n][m]=tmp;
	return f[n][m];
}

int main()
{
	scanf("%d%d",&n,&m);
	solve(n,m);
	printf("%.10lf %.10lf\n",f[n][m],1-f[n][m]);
	
	return 0;
}