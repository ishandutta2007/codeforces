#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,s;
    pair <int,int> a[100010];
    long long c[100010],d[100010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j].first;
            a[j].second=j;
        }
        s=0;
        sort(a,a+n);
        for(j=0;j<n;j++) {
            k=0;
            l=a[j].first;
            d[0]=0;
            while(j<n&&a[j].first==l) {
                c[k++]=a[j].second;
                d[k]=d[k-1]+c[k-1]+1;
                j++;
            }
            for(l=1;l<k;l++) {
                s+=d[l]*(n-c[l]);
            }
            j--;
        }
        cout<<s<<endl;
    }
    return 0;
}