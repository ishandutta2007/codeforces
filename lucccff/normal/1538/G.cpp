#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i,j,k,l,m,n,t,x,y,a,b;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>x>>y>>a>>b;
        if (x<y) {
            x+=y;
            y=x-y;
            x-=y;
        }
        if (a<b) {
            a+=b;
            b=a-b;
            a-=b;
        }
        if (a-b!=0) l=(x-y)/(a-b);
        else l=0;
        m=y/b;
        if (l>m) {
            cout<<m<<endl;
            continue;
        }
        y=y-l*b;
        x=x-l*a;
        k=y/(a+b);
        y=y-k*(a+b);
        x=x-k*(a+b);
        if (y>=b&&x>=a) {
            l++;
        }
        cout<<l+2*k<<endl;
    }
    return 0;
}