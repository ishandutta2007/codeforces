#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,w;
    int a[100010],b[100010];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>w;
        for(j=0;j<n;j++) {
            cin>>a[j];
            b[j]=0;
        }
        sort(a,a+n);
        k=1;
        l=0;
        b[0]+=a[n-1];
        for(j=n-2;j>=0;j--) {
            if (a[j]<a[j+1]) {
                l=0;
            }
            while((l<k)&&(b[l]+a[j]>w)) l++;
            if (l==k) b[k++]=a[j];
            else b[l]+=a[j];
        }
        cout<<k<<endl;
    }
    return 0;
}