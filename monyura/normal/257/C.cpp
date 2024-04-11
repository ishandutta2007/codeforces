#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);

double norm2(const pii &a)
{
    return sqrt((long double)(a.first*a.first + a.second*a.second));
}


bool cmp(const pii &a,const pii &b)
{
    double r1=atan2((double)a.second,(double)a.first);
    double r2=atan2((double)b.second,(double)b.first);
    if (fabs(r1-r2)<1e-8)
        return norm2(a)<norm2(b);
    return r1<r2;
}


long double getAng(const pii &a,const pii &b)
{
    long double ang = acos((a.first*b.first+a.second*b.second)/(norm2(a)*norm2(b)));
    int prod = a.first*b.second - a.second*b.first;
    if (prod>0) 
        ang = 2*PI- ang;
    return ang;
}

void run()
{
    pii A[100100];
    int n;
    cin>>n;
    rep(i,0,n)
        scanf("%d%d",&A[i].first,&A[i].second);
    sort(A,A+n,cmp);
    A[n]=A[0];
    long double minAng = 2*PI;
    bool was=false;
    rep(i,0,n)
        if (A[i].first*A[i+1].second-A[i].second*A[i+1].first!=0 || A[i].first*A[i+1].first<0 || A[i].second*A[i+1].second<0)
        {
            minAng = min(minAng,getAng(A[i],A[i+1]));
            was=true;
        }
    if (!was)
        minAng = 0.0;
    double res=minAng*180/PI;
    printf("%.8lf\n",res);
}



int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
    //freopen("barns.in","r",stdin);
    //freopen("barns.out","w",stdout);
#endif
    run();
#ifdef _MONYURA_
    printf("=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
}

/*
10 10 92
11 10 92
*/