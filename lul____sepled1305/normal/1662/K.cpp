#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
struct P{
    ld x,y;
    P operator+(P p){return (P){x+p.x,y+p.y};}
    P operator-(P p){return (P){x-p.x,y-p.y};}
    P operator*(ld c){return (P){x*c,y*c};}
    P operator/(ld c){return (P){x/c,y/c};}
    ld operator*(P p){return x*p.y-y*p.x;}
    ld operator%(P p){return x*p.x+y*p.y;}
    P norm(){return *this/dis();}
    ld dis(){return hypot(x,y);}
    void scan(){scanf("%Lf%Lf",&x,&y);}
}a,b,c;
P intersect(P s1,P e1,P s2,P e2){
    ld d=(e1-s1)*(e2-s2);
    ld p=(e1-s2)*(e2-s2),q=(e2-s2)*(s1-s2);
    return (s1*p+e1*q)/d;
}
P getetri(P u,P v,P w){
    P x=(v-u).norm(),y=((w-u)-x*(x%(w-u))).norm();
    ld d=(v-u).dis();
    return u+x*(d/2)-y*(d*sqrt(3)/2);
}
bool check(P u,P v){
    return u%v/u.dis()/v.dis()<=-0.5;
}

ld calc(P u,P v,P w){
    if(check(u-w,v-w))return (u-w).dis()+(v-w).dis();
    if(check(v-u,w-u))return (v-u).dis()+(w-u).dis();
    if(check(w-v,u-v))return (w-v).dis()+(u-v).dis();
    P o=intersect(getetri(u,v,w),w,getetri(u,w,v),v);
    return (u-o).dis()+(v-o).dis()+(w-o).dis();
}
ld sol(ld x,ld y){
    P p=(P){x,y};
    return max(calc(a,b,p),max(calc(b,c,p),calc(c,a,p)));
}
ld soly(ld x){
    ld l=-1e4,r=1e4;
    rep(tim,256){
        ld l2r=(l*2+r)/3,lr2=(l+r*2)/3;
        if(sol(x,l2r)<sol(x,lr2))r=lr2; else l=l2r;
    }
    return sol(x,l);
}
ld solx(){
    ld l=-1e4,r=1e4;
    rep(tim,256){
        ld l2r=(l*2+r)/3,lr2=(l+r*2)/3;
        if(soly(l2r)<soly(lr2))r=lr2; else l=l2r;
    }
    return soly(l);
}
int main() {
    a.scan(),b.scan(),c.scan();
    printf("%.15Lf\n",solx());
    return 0;
}