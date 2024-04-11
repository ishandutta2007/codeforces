#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,a,b,x,y,s1,s2,s3;
    s1=s2=0;
    cin>>n;
    k=n*n/2;
    l=n*n-k;
    for(i=0;i<n*n;i++) {
        cin>>a;
        if (s2==k) {
            if (a==1) {
                b=3;
            }
            else {
                b=1;
            }
            m=(s1++)%n+1;
            if (m*2>n+1) {
                x=((s1-1)/n)*2+2;
                if (n%2!=0) y=m*2-n-1;
                else y=m*2-n;
            }
            else {
                x=((s1-1)/n)*2+1;
                y=m*2-1;
            }
        }
        else if (s1==l) {
            if (a==2) {
                b=3;
            }
            else {
                b=2;
            }
            m=(s2++)%n+1;
            if (m*2>n) {
                x=((s2-1)/n)*2+2;
                if (n%2!=0) y=m*2-n;
                else y=m*2-n-1;
            }
            else {
                x=((s2-1)/n)*2+1;
                y=m*2;
            }
        }
        else {
            if (a==1) {
                b=2;
                m=(s2++)%n+1;
                if (m*2>n) {
                    x=((s2-1)/n)*2+2;
                    if (n%2!=0) y=m*2-n;
                    else y=m*2-n-1;
                }
                else {
                    x=((s2-1)/n)*2+1;
                    y=m*2;
                }
            }
            else {
                b=1;
                m=(s1++)%n+1;
                if (m*2>n+1) {
                    x=((s1-1)/n)*2+2;
                    if (n%2!=0) y=m*2-n-1;
                    else y=m*2-n;
                }
                else {
                    x=((s1-1)/n)*2+1;
                    y=m*2-1;
                }
            }
        }
        cout<<b<<' '<<x<<' '<<y<<endl<<flush;
    }
    return 0;
}