#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,x,y,a,b,c,d;
    cin>>n>>x>>y;
    a=b=c=d=0;
    for(i=0;i<n;i++) {
        cin>>k>>l;
        if (k<x) a++;
        if (k>x) b++;
        if (l<y) c++;
        if (l>y) d++;
    }
    m=0;
    if (a>m) m=a;
    if (b>m) m=b;
    if (c>m) m=c;
    if (d>m) m=d;
    if (m==a) {
        cout<<a<<endl;
        cout<<x-1<<' '<<y;
        return 0;
    }
    if (m==b) {
        cout<<b<<endl;
        cout<<x+1<<' '<<y;
        return 0;
    }
    if (m==c) {
        cout<<c<<endl;
        cout<<x<<' '<<y-1;
        return 0;
    }
    if (m==d) {
        cout<<d<<endl;
        cout<<x<<' '<<y+1;
        return 0;
    }
    return 0;
}