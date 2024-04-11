#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,x,y,q;
    long long a[300010],b[300010],c[20],d[20];
    char ch;
    cin>>k;
    x=1;
    for(i=0;i<k;i++) {
        c[i]=x;
        x<<=1;
    }
    y=0;
    for(i=k-1;i>=0;i--) {
        y+=c[i];
        d[i]=y;
    }
    d[k]=0;
    getchar();
    for(i=1;i<x;i++) {
        ch=getchar();
        if (ch=='1') {
            a[i]=1;
        }
        else if (ch=='0') {
            a[i]=0;
        }
        else {
            a[i]=-1;
        }
    }
    j=1;
    for(i=k-1;i>=0;i--) {
        if (i==k-1) for(j=d[i+1]+1;j<=d[i];j++) {
            if (a[j]==-1) b[j]=2;
            else b[j]=1;
        }
        else for(j=d[i+1]+1;j<=d[i];j++) {
            if (a[j]==0) {
                b[j]=b[(j-d[i+1])*2+d[i+2]-1];
            }
            else if (a[j]==1) {
                b[j]=b[(j-d[i+1])*2+d[i+2]];
            }
            else {
                b[j]=b[(j-d[i+1])*2+d[i+2]-1]+b[(j-d[i+1])*2+d[i+2]];
            }
        }
    }
    cin>>q;
    for(i=0;i<q;i++) {
        cin>>l;
        getchar();
        ch=getchar();
        if (ch=='1') {
            a[l]=1;
            for(j=k-1;j>=0;j--) {
                if (l<=d[j]) break;
            }
            if (j<k-1) b[l]=b[(l-d[j+1])*2+d[j+2]];
            else b[l]=1;
            for(j=j-1;j>=0;j--) {
                l=(l-d[j+2]+1)/2+d[j+1];
                if (a[l]==1) {
                    b[l]=b[(l-d[j+1])*2+d[j+2]];
                }
                else if (a[l]==0) {
                    b[l]=b[(l-d[j+1])*2+d[j+2]-1];
                }
                else {
                    b[l]=b[(l-d[j+1])*2+d[j+2]-1]+b[(l-d[j+1])*2+d[j+2]];
                }
            }
        }
        else if (ch=='0') {
            a[l]=0;
            for(j=k-1;j>=0;j--) {
                if (l<=d[j]) break;
            }
            if (j<k-1) b[l]=b[(l-d[j+1])*2+d[j+2]-1];
            else b[l]=1;
            for(j=j-1;j>=0;j--) {
                l=(l-d[j+2]+1)/2+d[j+1];
                if (a[l]==1) {
                    b[l]=b[(l-d[j+1])*2+d[j+2]];
                }
                else if (a[l]==0) {
                    b[l]=b[(l-d[j+1])*2+d[j+2]-1];
                }
                else {
                    b[l]=b[(l-d[j+1])*2+d[j+2]-1]+b[(l-d[j+1])*2+d[j+2]];
                }
            }
        }
        else {
            a[l]=-1;
            for(j=k-1;j>=0;j--) {
                if (l<=d[j]) break;
            }
            if (j<k-1) b[l]=b[(l-d[j+1])*2+d[j+2]]+b[(l-d[j+1])*2+d[j+2]-1];
            else b[l]=2;
            for(j=j-1;j>=0;j--) {
                l=(l-d[j+2]+1)/2+d[j+1];
                if (a[l]==1) {
                    b[l]=b[(l-d[j+1])*2+d[j+2]];
                }
                else if (a[l]==0) {
                    b[l]=b[(l-d[j+1])*2+d[j+2]-1];
                }
                else {
                    b[l]=b[(l-d[j+1])*2+d[j+2]-1]+b[(l-d[j+1])*2+d[j+2]];
                }
            }
        }
        cout<<b[x-1]<<endl;
    }
    return 0;
}