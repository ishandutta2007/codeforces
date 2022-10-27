#include<bits/stdc++.h>
using namespace std;
using pii=pair<double,double>;
struct triple{
    double f,s,t;
};
double a,b,c;
double ans;
pii p1,p2;
triple u,v,w,z;
double distance(pii x,pii y){
    return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
}
triple ver(pii x){
    //a*x+b*y*c=0
    triple tmp={0.0,0.0,0.0};
    tmp.f=x.first;
    tmp.s=((-a*x.first)-c)/b;
    tmp.t=abs(tmp.s-x.second);
    return tmp;
}
triple hor(pii x){
    triple tmp={0.0,0.0,0.0};
    tmp.s=x.second;
    tmp.f=((-b*x.second)-c)/a;
    tmp.t=abs(tmp.f-x.first);
    return tmp;

}
double mindist(triple x,triple y){
    double tmp=1e18;
    return distance(make_pair(x.f,x.s),make_pair(y.f,y.s))+x.t+y.t;
}

int main(){
    cin>>a>>b>>c;
    cin>>p1.first>>p1.second>>p2.first>>p2.second;
    ans=(abs(p1.first-p2.first)+abs(p1.second-p2.second));
    u=hor(p1),v=ver(p1),w=hor(p2),z=ver(p2);
    ans=min({ans,mindist(u,w),mindist(u,z),mindist(v,w),mindist(v,z)});
    printf("%.15f\n",ans);
}