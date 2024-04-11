#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int n;
long long H;
long long x[maxn];
long long y[maxn];
long long a,b,c;
long long val(int i) {
    return x[i]*a+y[i]*b+c;
}
void mx(int i) {
    a=(y[i]-H);
    b=(x[n-1]-x[i]);
    c=y[i]*(x[i]-x[n-1])-x[i]*(y[i]-H);
    //cout<<val(i)<<endl;
    assert(x[i]*a+y[i]*b+c==0 && x[n-1]*a+b*H+c==0);
}
pair<long double,long double> inter(int i) {
    //cout<<i<<" "<<(a*(x[i+1]-x[i])+b*(y[i+1]-y[i]))<<endl;
    long double t=(0.0-c-a*x[i]-b*y[i])/(a*(x[i+1]-x[i])+b*(y[i+1]-y[i]));
    return {x[i]+t*(x[i+1]-x[i]),y[i]+t*(y[i+1]-y[i])};
}
int main() {
    scanf("%d %lld",&n,&H);
    for(int i=0;i<n;i++) {
        scanf("%lld %lld",&x[i],&y[i]);
    }
    H+=y[n-1];
    mx(n-1);
    long double ans=0;
    for(int i=n-1;i>0;i--) {
        //cout<<i<<" "<<val(i)<<" "<<val(i-1)<<endl;
        if(val(i)>=0 && val(i-1)>=0) {
            ans=ans+sqrt(0.0+(x[i-1]-x[i])*(x[i-1]-x[i])+(y[i-1]-y[i])*(y[i-1]-y[i]));
            //cout<<i<<" 1 "<<sqrt(0.0+(x[i-1]-x[i])*(x[i-1]-x[i])+(y[i-1]-y[i])*(y[i-1]-y[i]))<<endl;
            if(val(i)>val(i-1)) mx(i);
            else mx(i-1);
        }
        else {
            if(val(i)>=0) {
                pair<long double,long double> ip=inter(i-1);
                mx(i);
                //cout<<ip.first<<" "<<ip.second<<endl;
                ans=ans+sqrt((x[i]-ip.first)*(x[i]-ip.first)+(y[i]-ip.second)*(y[i]-ip.second));
                //cout<<sqrt((x[i]-ip.first)*(x[i]-ip.first)+(y[i]-ip.second)*(y[i]-ip.second))<<endl;
            }
            else {
                if(val(i-1)>=0) {
                    pair<long double,long double> ip=inter(i-1);
                    mx(i-1);
                    //cout<<ip.first<<" "<<ip.second<<endl;
                    ans=ans+sqrt((x[i-1]-ip.first)*(x[i-1]-ip.first)+(y[i-1]-ip.second)*(y[i-1]-ip.second));
                    //cout<<sqrt((x[i-1]-ip.first)*(x[i-1]-ip.first)+(y[i-1]-ip.second)*(y[i-1]-ip.second))<<endl;
                }
            }
        }
    }
    //cout<<ans<<endl;
    printf("%.10Lf",ans);
    return 0;
}