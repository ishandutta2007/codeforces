#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,k1;
    int a[2010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>k1;
        getchar();
        for(j=0;j<n;j++) {
            if (getchar()=='(') a[j]=1;
            else a[j]=-1;
        }
        cout<<n/2<<endl;
        for(j=0;j<k1-1;j++) {
            if (a[j*2]!=1) {
                k=j*2+1;
                while(k<n&&a[k]==-1) k++;
                if (k==n) return 0;
                cout<<j*2+1<<' '<<k+1<<endl;
                for(l=j*2;l<(j*2+k+1)/2;l++) {
                    m=a[l];
                    a[l]=a[j*2+k-l];
                    a[j*2+k-l]=m;
                }
            }
            else if (a[j*2+1]==1) {
                k=j*2+2;
                while(k<n&&a[k]==1) k++;
                if (k==n) return 0;
                cout<<j*2+1+1<<' '<<k+1<<endl;
                for(l=j*2+1;l<(j*2+k+2)/2;l++) {
                    m=a[l];
                    a[l]=a[j*2+k+1-l];
                    a[j*2+k+1-l]=m;
                }
            }
            else {
                cout<<j*2+1<<' '<<j*2+1<<endl;
            }
        }

        for(j=(k1-1)*2;j<n/2+k1-1;j++) {
            if (a[j]!=1) {
                k=j;
                while(k<n&&a[k]==-1) k++;
                if (k==n) return 0;
                cout<<j+1<<' '<<k+1<<endl;
                for(l=j;l<(j+k+1)/2;l++) {
                    m=a[l];
                    a[l]=a[j+k-l];
                    a[j+k-l]=m;
                }
            }
            else {
                cout<<j+1<<' '<<j+1<<endl;
            }
        }
    }
    return 0;
}