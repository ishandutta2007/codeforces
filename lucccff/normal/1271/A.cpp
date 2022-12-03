#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    if (b>c) b=c;
    if (e>f) {
        if (d>a) {
            if (d>=a+b) {
                cout<<a*e+b*f;
            }
            else {
                cout<<a*e+(d-a)*f;
            }
        }
        else {
            cout<<d*e;
        }
    }
    else {
        if (d>b) {
            if (d>=a+b) {
                cout<<a*e+b*f;
            }
            else {
                cout<<(d-b)*e+b*f;
            }
        }
        else {
            cout<<d*f;
        }
    }
    return 0;
}