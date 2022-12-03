#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t,g,s,b;
    long long a[400010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        k=0;
        for(j=1;j<n;j++) {
            if (a[j]<a[j-1]) k++;
            if (k==3) break;
        }
        if (j*2>n) {
            cout<<0<<' '<<0<<' '<<0<<endl;
            continue;
        }
        k=j=0;
        while(a[j]==a[k]) j++;
        g=j;
        for(;j<n;) {
            k=j;
            while(j<n&&a[k]==a[j]) {
                j++;
            }
            if (j>2*g) break;
        }
        s=j-g;

        for(;j<n;) {
            k=j;
            while(j<n&&a[k]==a[j]) {
                j++;
            }
            if (j>2*g+s) break;
        }
        if (j*2>n) {
            cout<<0<<' '<<0<<' '<<0<<endl;
            continue;
        }
        for(;j<n;) {
            k=j;
            while(j<n&&a[k]==a[j]) j++;
            if (j*2>n) break;
        }
        cout<<g<<' '<<s<<' '<<k-g-s<<endl;
    }
    return 0;
}