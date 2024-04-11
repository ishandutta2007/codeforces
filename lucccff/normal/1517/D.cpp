#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,sum,x,y;
    int a[501][501],b[501][501],s[501][501][10];
    cin>>n>>m>>k;
    for(i=0;i<n;i++) {
        for(j=0;j<m-1;j++) {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n-1;i++) {
        for(j=0;j<m;j++) {
            cin>>b[i][j];
        }
    }
    if (k%2!=0) {
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                cout<<-1<<' ';
            }
            cout<<endl;
        }
        return 0;
    }
    k=k/2;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            sum=10000007;
            if (i>0) {
                sum=b[i-1][j];
            }
            if (j>0) {
                if (sum>a[i][j-1]) {
                    sum=a[i][j-1];
                }
            }
            if (i<n-1) {
                if (sum>b[i][j]) sum=b[i][j];
            }
            if (j<m-1) {
                if (sum>a[i][j]) sum=a[i][j];
            }
            s[i][j][0]=sum;
        }
    }

    for(l=1;l<k;l++) {
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                sum=10000007;
                if (i>0) {
                    sum=b[i-1][j]+s[i-1][j][l-1];
                }
                if (j>0) {
                    if (sum>a[i][j-1]+s[i][j-1][l-1]) {
                        sum=a[i][j-1]+s[i][j-1][l-1];
                    }
                }
                if (i<n-1) {
                    if (sum>b[i][j]+s[i+1][j][l-1]) sum=b[i][j]+s[i+1][j][l-1];
                }
                if (j<m-1) {
                    if (sum>a[i][j]+s[i][j+1][l-1]) sum=a[i][j]+s[i][j+1][l-1];
                }
                s[i][j][l]=sum;
            }
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cout<<2*s[i][j][k-1]<<' ';
        }
        cout<<endl;
    }
    return 0;
}