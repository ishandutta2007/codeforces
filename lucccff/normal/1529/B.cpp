#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    long long a[100010],b[100010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        k=0;
        for(j=0;j<n;j++) {
            cin>>a[j];
            if (a[j]<=0) b[k++]=a[j];
        }
        sort(b,b+k);
        l=1e9;
        for(j=0;j<k-1;j++) {
            if (b[j+1]-b[j]<l) l=b[j+1]-b[j];
        }
        int f=0;
        for(j=0;j<n;j++) {
            if (a[j]>0&&a[j]<=l) f=1;
        }
        cout<<k+f<<endl;
    }
    return 0;
}