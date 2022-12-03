#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i,j,k,l,m,n,t;
    long long a[200010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        k=0;
        for(j=0;j<n;j++) {
            cin>>a[j];
            k+=a[j];
        }
        if (k%n!=0) {
            cout<<-1<<endl;
            continue;
        }
        k=k/n;
        l=0;
        for(j=0;j<n;j++) {
            if (a[j]>k) l++;
        }
        cout<<l<<endl;
    }
    return 0;
}