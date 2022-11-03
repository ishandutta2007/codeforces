#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
#include<set>
#include<vector>
//#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
typedef long double ld;
const int P=1000000007;
const int N=200005;

double L,r,Mid,ans,a1,a2,a3,a4,Minn,maxx,EKKKK,jabby,fem,misd;

bool check(double x){
	EKKKK=a1*a4;
	EKKKK=min(EKKKK,min((a1-x)*(a4+x),min(min(EKKKK,(a1-x)*(a4-x)),min(EKKKK,(a1+x)*(a4+x)))));
	EKKKK=min(EKKKK,(a1+x)*(a4-x)); fem=a1*a4;
	fem=max(fem,(a1-x)*(a4+x)); fem=max(fem,(a1-x)*(a4-x)); fem=max(fem,(a1+x)*(a4+x)); fem=max(fem,(a1+x)*(a4-x));	 jabby=a2*a3;
	jabby=min(jabby,(a2-x)*(a3+x)); jabby=min(jabby,(a2-x)*(a3-x)); jabby=min(jabby,(a2+x)*(a3+x));
	jabby=min(jabby,(a2+x)*(a3-x)); misd=a2*a3;
	misd=max(misd,(a2-x)*(a3+x)); misd=max(misd,(a2-x)*(a3-x)); misd=max(misd,(a2+x)*(a3+x)); misd=max(misd,(a2+x)*(a3-x));
	Minn=EKKKK-misd; maxx=fem-jabby;
	if(Minn<=0&&maxx>=0)return 1;
	return 0;
}

int main(){
	int xmg=0;
	L=0;r=1e11;
	scanf("%lf%lf%lf%lf",&a1,&a2,&a3,&a4);
	while(L+1e-10<=r && xmg<=500){
		Mid=(L+r)/2.;
		if(check(Mid))ans=Mid,r=Mid-1e-10; else L=Mid+1e-10;
		xmg++;
	}
	printf("%.9lf\n",ans);
}