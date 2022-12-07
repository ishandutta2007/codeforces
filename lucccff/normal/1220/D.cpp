#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i,j,k,l,m,n;
    long long a[200010],b[200010],c[60];
    cin>>n;
    memset(c,0,sizeof(c));
    for(i=0;i<n;i++) {
        cin>>a[i];
        k=a[i];
        l=0;
        while(k%2==0) {
            k=k>>1;
            l++;
        }
        c[l]++;
        b[i]=l;
    }
    k=0;
    for(i=0;i<60;i++) {
        if (c[i]>k) {
            k=c[i];
            l=i;
        }
    }
    cout<<n-k<<endl;
    for(i=0;i<n;i++) {
        if (b[i]!=l) cout<<a[i]<<' ';
    }
    return 0;
}