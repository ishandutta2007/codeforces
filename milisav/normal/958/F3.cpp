#include<bits/stdc++.h>
using namespace std;
struct comp
{
    double x,y;
    comp(double xi,double yi) {
        x=xi;
        y=yi;
    }
    comp(double xi) {
        x=xi;
        y=0.0;
    }
    comp() {
        x=0.0;
        y=0.0;
    }
};
comp operator + (comp a,comp b) {
    return comp(a.x+b.x,a.y+b.y);
}
comp operator - (comp a,comp b) {
    return comp(a.x-b.x,a.y-b.y);
}
comp operator * (comp a,comp b) {
    return comp(a.x*b.x-a.y*b.y,a.x*b.y+b.x*a.y);
}
comp polarcomp (double r,double arg){
    return comp(r*cos(arg),r*sin(arg));
}
long long n,m,k;
vector<long long> a[2000005];
long long ps[10000000];
vector<long long> z;
long long f;
vector<comp> pm[3];
long long inverse(long long i)
{
    long long j=1;
    long long rt=0;
    long long l=f>>1;
    while(j<l) {
        if((i&j)) rt+=l;
        if((i&l)) rt+=j;
        j=(j<<1);
        l=(l>>1);
    }
    if(j==l && (i&j)==l) rt+=l;
    return rt;
}
void dft(long long ind,bool inv) {
    for(long long i=0;i<pm[ind].size();i++) {
        if(i<inverse(i)) swap(pm[ind][i],pm[ind][inverse(i)]);
    }
    comp d,w,x,y;
    for(long long l=2;l<=f;l=(l<<1)) {
        if(!inv) w=polarcomp(1.0,2.00*acos(-1.0)/double(l));
        else w=polarcomp(1.0,-2.00*acos(-1.0)/double(l));
        //cout<<w.x<<" "<<w.y<<endl;
        for(long long i=0;i<f;i=i+l) {
            d=comp(1.0,0.0);
            for(long long j=i;j<i+(l>>1);j++) {
                x=pm[ind][j];
                y=pm[ind][j+(l>>1)]*d;
                pm[ind][j]=x+y;
                pm[ind][j+(l>>1)]=x-y;
                d=d*w;
            }
        }
        /*for(int i=0;i<pm[ind].size();i++) cout<<"("<<pm[ind][i].x<<","<<pm[ind][i].y<<") ";
        cout<<endl;*/
    }
}
vector<long long> fft(vector<long long> x,vector<long long> y) {
    pm[0].clear();
    f=ps[x.size()+y.size()];
    while(pm[0].size()<f) pm[0].push_back(0.00);
    pm[1].clear();
    while(pm[1].size()<f) pm[1].push_back(0.00);
    pm[2].clear();
    while(pm[2].size()<f) pm[2].push_back(0.00);
    for(long long i=0;i<x.size();i++) pm[0][i]=x[i];
    for(long long i=0;i<y.size();i++) pm[1][i]=y[i];
    dft(0,false);
    dft(1,false);
    for(long long i=0;i<pm[2].size();i++) pm[2][i]=pm[0][i]*pm[1][i];
    //for(int i=0;i<pm[0].size();i++) cout<<"("<<pm[0][i].x<<","<<pm[0][i].y<<") ("<<pm[1][i].x<<","<<pm[1][i].y<<") ("<<pm[2][i].x<<","<<pm[2][i].y<<")"<<endl;
    dft(2,true);
    for(long long i=0;i<pm[2].size();i++) pm[2][i]=comp(pm[2][i].x/((double)(f)),pm[2][i].y/((double)(f)));
    //f=(f>>1);
    z.resize(pm[2].size());
    //cout<<f<<" "<<x.size()<<" "<<y.size()<<endl;
    for(long long i=0;i<z.size();i++) {
        z[i]=((long long)round(pm[2][i].x))%1009;
        if(z[i]<0) z[i]+=1009;
        //cout<<"("<<pm[2][i].x<<","<<pm[2][i].y<<")"<<endl;
    }
    while(z[z.size()-1]==0) z.pop_back();
    return z;

}
vector<long long> mul(long long l,long long r){
    //cout<<l<<" "<<r<<endl;
    if(l==r) return a[l];
    return fft(mul(l,((l+r)>>1)),mul(((l+r)>>1)+1,r));
}
int main()
{
    long long x;
    scanf("%lld %lld %lld",&n,&m,&k);
    ps[1]=1;
    for(long long i=2;i<1e7;i++) {
        ps[i]=ps[i-1];
        if(i>ps[i]) ps[i]=2*ps[i];
        //cout<<i<<" "<<ps[i]<<endl;
    }
    for(long long i=1;i<=m;i++) a[i].push_back(1);
    for(long long i=0;i<n;i++) {
        scanf("%lld",&x);
        a[x].push_back(1);
    }
    printf("%lld",mul(1,m)[k]);
    return 0;
}