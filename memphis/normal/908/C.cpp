#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <bitset>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define fi first
#define se second

using namespace std;

const int N=1005;

int n;
long double r,a[N],xx[N];
double tmp;

int main(){
    scanf("%d",&n);
    scanf("%lf",&tmp);
    r=tmp;
    rep(i,1,n) a[i]=r;
    long double vv=2*r*2*r;
    rep(i,1,n){
        long double x;
        scanf("%lf",&tmp);
        x=tmp;
        rep(j,1,i-1){
            long double cc=vv-(x-xx[j])*(x-xx[j]);
            if(abs(cc)<1e-8) cc=0;
            if(cc<0) continue;
            cc=sqrt(cc);
            long double th=a[j]+cc;
            a[i]=max(a[i],th);
        }
        xx[i]=x;
    }
    rep(i,1,n) 
    printf("%.9lf ",(double)a[i]);
    puts("");
}