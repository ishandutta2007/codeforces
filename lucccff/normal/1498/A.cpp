#include <bits/stdc++.h>
using namespace std;

long long gcd(long long m, long long n) {
    long long r;
    r=m%n;
    while (r!=0) {
        m=n;
        n=r;
        r=m%n;
    }
    return n;
}

int main(){
    long long i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        k=0;
        l=n;
        while (l>0) {
            k+=l%10;
            l=l/10;
        }
        if (gcd(n,k)!=1) {
            cout<<n<<endl;
            continue;
        }
        k=0;
        l=n+1;
        while (l>0) {
            k+=l%10;
            l=l/10;
        }
        if (gcd(n+1,k)!=1) {
            cout<<n+1<<endl;
            continue;
        }
        k=0;
        l=n+2;
        while (l>0) {
            k+=l%10;
            l=l/10;
        }
        if (gcd(n+2,k)!=1) {
            cout<<n+2<<endl;
            continue;
        }
    }
    return 0;
}