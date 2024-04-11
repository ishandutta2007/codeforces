#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long i,j,k,l,m,n,t,x,s;
    cin>>n>>k;
    l=0;
    x=1;
    while(x<=n) {
        x<<=1;
        l++;
    }
    m=0;
    x=1;
    while(x-2<k) {
        x<<=1;
        m++;
    }
    t=n>>(m-2);
    if (t%2==1) t--;
    if (n-(t<<(m-2))<((long long)1<<(m-1))-1) {
        if (n-(t<<(m-2))+((long long)1<<(m-1))-1<k) {
            t-=2;
        }
    }
    m=0;
    x=1;
    while(x-1<k) {
        x<<=1;
        m++;
    }
    s=n>>(m-1);
    if (s%2==0) s--;
    if (n-(s<<(m-1))<((long long)1<<(m-1)-1)) {
        if (n-(s<<(m-1))+((long long)1<<(m-1))<k) {
            s-=2;
        }
    }
    if (s>t) cout<<s;
    else cout<<t;
    return 0;
}