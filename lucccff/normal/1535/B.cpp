#include <bits/stdc++.h>
using namespace std;

int gcd(int m,int n) {
    if (m<n) {
        m+=n;
        n=m-n;
        m-=n;
    }
    int r=m%n;
    while(r>0) {
        m=n;
        n=r;
        r=m%n;
    }
    return n;
}

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t,s;
    long long a[2010],b[2010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        m=0;
        for(j=0;j<n;j++) {
            if (a[j]%2!=0) {
                b[m++]=a[j];
            }
        }
        s=(n+m-1)*(n-m)/2;
        for(j=0;j<m;j++) {
            for(k=j+1;k<m;k++) {
                if (gcd(b[j],b[k])>1) s++;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}