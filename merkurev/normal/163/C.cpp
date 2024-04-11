#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

double ans[200500];
double a[200500];
int n,v1,v2,L;
double eps=1e-15;

bool doubleEqual(double a,double b)
{
    return fabs(a-b)<eps;
}

int find(double x)
{
    int le = 0;
    int ri = 2*n;

    while (ri-le>1)
    {
        int m = (ri+le)/2;
        if (a[m]>x+eps)
            ri=m;
        else
            le=m;
    }
    return ri;
}


int main () {
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);


    scanf("%d%d%d%d",&n,&L,&v1,&v2);
    double d = double(L) * double(v2) / double(v1+v2);
    for (int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
    }
    for (int i=0;i<n;i++)
    {
        a[n+i]=2*L+a[i];
    }
    a[2*n]=5*L;
    double l = a[0];
    double r = a[0]+d;
    double diff=0;
    int num=0;

    while (true)
    {
        int lbigger = find(l);
        int rbigger = find(r);

        double rd = a[rbigger] - r;
        
        if (doubleEqual(rd,0))
            rd=2*L;
        
        double ld = a[lbigger] - l;
        
        if (doubleEqual(ld,0))
            ld=2*L;

        num=rbigger-lbigger;
        
        double newdiff = min( rd , ld ); 

        l+=newdiff;
        r+=newdiff;

        ans[num] += newdiff / double(2 * L);

        diff = newdiff;
    

        if (doubleEqual(l,a[n]))
            break;
    }
    for (int i=0;i<=n;i++)
        printf("%.12lf\n",ans[i]);



    return 0;
}