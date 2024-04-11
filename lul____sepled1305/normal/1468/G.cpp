#include<bits/stdc++.h>
#define double long double
#define point pair<double,double>
#define pdd pair<double,double>
#define x first
#define y second
using namespace std;
 
struct segment
{
    point st,ed;
 
    segment(point a, point b)
    {
        st = a, ed = b;
    }
 
    point ration(double r)
    {
        double x = ed.x + (st.x - ed.x) * r;
        double y = ed.y + (st.y - ed.y) * r;
        return {x,y};
    }
};
 
struct line
{
    point pt;
    double m;
 
    line(point a, point b)
    {
        m = (b.y-a.y)/(b.x-a.x);
        pt = a;
    }
 
    line(point x, double theta)
    {
        pt = x;
        m = theta;
    }
};
 
point line_intersect(line a, line b)
{
    double x = ((b.pt.y-a.pt.y)-(b.m*b.pt.x-a.m*a.pt.x))/(a.m - b.m);
    double y = a.m*x + a.pt.y - a.pt.x*a.m;
    return {x,y};
}
 
double dist(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
 
double slope(point pt, point center)
{
    double co = (center.y - pt.y)/(center.x - pt.x);
    return co;
}
 
int main()
{
    int n,H,i;
    cin>>n>>H;
    vector<segment> v;
    point last;
    int a,b;
    cin>>a>>b;
    last = {a,b};
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        point cur = {a,b};
        v.push_back(segment(last,cur));
        last = cur;
    }
    point center = {last.x,last.y+H};
    double cover = 1e10;
    double dis = 0;
    while(!v.empty())
    {
        segment cur = v.back();
        v.pop_back();
        double stsl = slope(cur.st,center);
        double edsl = slope(cur.ed,center);
        //cout<<stsl<<' '<<edsl<<endl;
        if(stsl > cover)
            continue;
        else if(edsl > 1e9)
        {
            dis+=dist(cur.st,cur.ed);
            cover = stsl;
        }
        else if(abs(stsl-edsl) < 1e-10)
        {
            dis+=dist(cur.st,cur.ed);
        }
        else
        {
            line a = line(center,cover);
            line b = line(cur.st,cur.ed);
            point here = line_intersect(a,b);
            cover = stsl;
            dis += dist(here,cur.st);
        }
        //cout<<dis<<endl;
    }
    cout<<setprecision(20)<<dis;
    return 0;
}