#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

struct point{
    double x,y;
    int t;
    point operator+(point p);
    point operator-(point p);
    bool operator==(point p);
    point operator=(point p);
    point operator+=(point p);
    point operator-=(point p);
    bool operator<(point p);
    bool operator>(point p);
    point operator/(double d);
    point operator*(double d);
    point operator/=(double d);
    point operator*=(double d);
    void print();
    point get();
    double angle();
    double tg();
};
struct line{
    double a,b,c;
    line get();
    double angle();
    double tg();
};

point make_point(double a,double b);

double seg_length(point p1,point p2);
const double PI=3.14159265358979;
const double eps=1e-8;
const point ZERO=make_point(0,0);



point point::operator+(point p){
    point tmp;
    tmp.x=x+p.x;
    tmp.y=y+p.y;
    return tmp;
}
point point::operator-(point p){
    point tmp;
    tmp.x=x-p.x;
    tmp.y=y-p.y;
    return tmp;
}
bool point::operator==(point p){
    if(p.x==x&&p.y==y) return true;
    return false;
}
point point::operator=(point p){
    x=p.x;
    y=p.y;
    t=p.t;
    return *this;
}
void point::print(){
    printf("%.8lf %.8lf",x,y);
}
point point::operator+=(point p){
    x+=p.x;
    y+=p.y;
    return *this;
}
point point::operator-=(point p){
    x-=p.x;
    y-=p.y;
    return *this;
}
bool point::operator<(point p){
    if(x==p.x) return y<p.y;
    return x<p.x;
}
bool point::operator>(point p){
    if(x==p.x) return y>p.y;
    return x>p.x;
}
point point::operator/(double d){
    point tmp;
    tmp=make_point(x/d,y/d);
    return tmp;
}
point point::operator*(double d){
    point tmp;
    tmp=make_point(x*d,y*d);
    return tmp;
}
point point::operator/=(double d){
    x/=d;
    y/=d;
    return *this;
}
point point::operator*=(double d){
    x*=d;
    y*=d;
    return *this;
}
point point::get(){
    scanf("%lf%lf",&x,&y);
    return *this;
}
double point::angle(){
    double ans;
    ans=acos(x/seg_length(ZERO,*this));
    if(y<0) ans=2*PI-ans;
    return ans;
}
double point::tg(){
    if(x!=0){
        return y/x;
    }
    return 1e308;
}


line line::get(){
    scanf("%lf%lf%lf",&a,&b,&c);
    return *this;
}
double line::angle(){
    return acos(b/sqrt(a*a+b*b));
}
double line::tg(){
    if(b!=0){
        return -a/b;
    }
    return 1e308;
}

double seg_length(point p1,point p2){
    return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
point make_point(double a,double b){
    point p;
    p.x=a;
    p.y=b;
    return p;
}
line make_line(double x,double y,double z){
    line l;
    l.a=x;
    l.b=y;
    l.c=z;
    return l;
}
double vector_angle(point p1,point p2){ 
    if(p1==ZERO||p2==ZERO) return PI;
    double an1,an2,ans;
    an1=p1.angle();
    an2=p2.angle();
    ans=min(abs(an1-an2),2*PI-abs(an1-an2));
    return ans;
}
double area(point p1,point p2,point p3){
    return (double)((p1-p2).x*(p3-p1).y-(p2-p1).y*(p3-p1).x);
}
double point_line_dist(point p,line l){
    double ans;
    ans=(double)(p.x*l.a+p.y*l.b+l.c)/sqrt((double)l.a*l.a+l.b*l.b);
    return ans;
}
line ptol(point p,point q){
    double a,b,c;
    if(q.x==p.x){
        return make_line(1,0,-p.x);
    }
    if(q.y==p.y){
        return make_line(0,1,-p.y);
    }
    p=q-p;
    a=p.y;
    b=-p.x;
    c=(q.y-q.x/p.x*p.y);
    c=-c*b;
    return make_line(a,b,c);
}
point inter(line l1,line l2){
    double x,y;
    if(l2.a==0){
        y=-l2.c/l2.b;
    }else{
        y=-(l1.c-l2.c*(l1.a/l2.a))/(l1.b-l2.b*(l1.a/l2.a));
    }
    if(l1.a==0){
        x=-(l2.b*y+l2.c)/l2.a;
    }else{
        x=-(l1.b*y+l1.c)/l1.a;
    }
    return make_point(x,y);
}
bool ponl(point p,line l){
    if(l.a*p.x+l.b*p.y+l.c==0) return true;
    return false;
}

point mass(vector<pair<point,double>> v){
    size_t n=v.size(),i;
    point ans;
    double ms=0;
    ans=v[0].first;
    ms=v[0].second;
    FOR(i,1,n){
        ans=(ans*ms+v[i].first*v[i].second)/(ms+v[i].second);
        ms+=v[i].second;
    }
    return ans;
}

void solve(){
    point h,u;
    int ans=0,n,i;
    line l;
    h.get();
    u.get();
    scanf("%d",&n);
    For(i,n){
        l.get();
        if((point_line_dist(h,l)<0)^(point_line_dist(u,l)<0)) ans++;
    }
    printf("%d",ans);
}

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifdef HOME
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    solve();
    return 0;
}