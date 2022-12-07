#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;
const int MAXN=200010;
const double pi=acos(-1);
int n;
double X,Y,v,T;
double x[MAXN],y[MAXN],r[MAXN];
vector<pair<double,double> > intervals;
void add(double l,double r)
{
    if(l>r) swap(l,r);
    if(l<-pi)
    {
        intervals.push_back(make_pair(l+pi+pi,pi));
        intervals.push_back(make_pair(-pi,r));
    }
    else if(r>pi)
    {
        intervals.push_back(make_pair(-pi,r-pi-pi));
        intervals.push_back(make_pair(l,pi));
    }
    else intervals.push_back(make_pair(l,r));
}
void work(double x,double y,double r)
{
    double alpha=atan2(y,x);
    double d=sqrt(x*x+y*y);
    if(r*r>=x*x+y*y) {puts("1");exit(0);}
    double l=v*T;
    if(l<d-r) return;
    if(l>sqrt(d*d-r*r)) l=sqrt(d*d-r*r);
    double beta=acos((x*x+y*y+l*l-r*r)/(2*d*l));
    add(alpha-beta,alpha+beta);
}
double calc()
{
    sort(intervals.begin(),intervals.end());
    int l=0;
    double res=0;
    while(l<intervals.size())
    {
        double s=intervals[l].first,m=intervals[l].second;
        l++;
        while(l<intervals.size()&&intervals[l].first<=m)
        {
            m=max(m,intervals[l].second);
            l++;
        }
        res+=m-s;
    }
    return res/(pi+pi);
}
int main()
{
    scanf("%lf%lf%lf%lf",&X,&Y,&v,&T);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
    for(int i=1;i<=n;i++) work(x[i]-X,y[i]-Y,r[i]);
    printf("%.010lf\n",calc());
    return 0;
}