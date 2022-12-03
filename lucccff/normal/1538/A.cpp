#include <bits/stdc++.h>
using namespace std;

int main() {
    int i,j,k,l,m,n,t;
    pair <int,int> a[400];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>k;
            a[j]=make_pair(k,j);
        }
        sort(a,a+n);
        m=n-abs(a[0].second-a[n-1].second)+1;
        k=__max(a[0].second,a[n-1].second)+1;
        l=n-__min(a[0].second,a[n-1].second);
        j=n;
        if (m<j) j=m;
        if (k<j) j=k;
        if (l<j) j=l;
        cout<<j<<endl;
    }
    return 0;
}