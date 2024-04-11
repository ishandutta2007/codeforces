#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
int n;
long double x[maxn];
long double y[maxn];
bool pos(long double r) {
    long double mn=-1e28;
    long double mx=1e28;
    for(int i=0;i<n;i++) {
        if(y[i]>=2*r) return false;
        long double dx=sqrt(2*r*y[i]-y[i]*y[i]);
        mn=max(mn,x[i]-dx);
        mx=min(mx,x[i]+dx);
    }
    if(mn<mx) return true;
    return false;
}
int main() {
    scanf("%d",&n);
    int cp=0,cn=0;
    for(int i=0;i<n;i++) {
        scanf("%Lf %Lf",&x[i],&y[i]);
        if(y[i]>0) cp++;
        if(y[i]<0) cn++;
        y[i]=abs(y[i]);
    }
    if(cp>0 && cn>0) {
        printf("-1");
        return 0;
    }
    long double l=0;
    long double r=1e18;
    int iter=200;
    while(iter--) {
        long double m=(l+r)/2;
        if(pos(m)) r=m;
        else l=m;
    }
    printf("%.10Lf",l);
    return 0;
}