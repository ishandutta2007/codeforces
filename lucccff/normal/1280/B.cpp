#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,f;
    long long a[66][66];
    char ch;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>m;
        l=0;
        f=0;
        for(j=0;j<n;j++) {
            getchar();
            for(k=0;k<m;k++) {
                ch=getchar();
                if (ch=='A') {
                    a[j][k]=1;
                    f=1;
                }
                else {
                    a[j][k]=0;
                    l=1;
                }
            }
        }
        if (!l) {
            cout<<0<<endl;
            continue;
        }
        if (!f) {
            cout<<"MORTAL"<<endl;
            continue;
        }

        f=1;
        for(j=0;j<n;j++) {
            if (a[j][0]==0) f=0;
        }
        if (f==1) {
            cout<<1<<endl;
            continue;
        }
        f=1;
        for(j=0;j<n;j++) {
            if (a[j][m-1]==0) f=0;
        }
        if (f==1) {
            cout<<1<<endl;
            continue;
        }
        f=1;
        for(j=0;j<m;j++) {
            if (a[0][j]==0) f=0;
        }
        if (f==1) {
            cout<<1<<endl;
            continue;
        }
        f=1;
        for(j=0;j<m;j++) {
            if (a[n-1][j]==0) f=0;
        }
        if (f==1) {
            cout<<1<<endl;
            continue;
        }

        if (a[0][0]==1||a[0][m-1]==1||a[n-1][0]==1||a[n-1][m-1]==1) {
            cout<<2<<endl;
            continue;
        }
        //f=1;
        for(j=1;j<n-1;j++) {
            f=1;
            for(k=0;k<m;k++) {
                if (a[j][k]==0) f=0;
            }
            if (f==1) break;
        }
        if (f==1) {
            cout<<2<<endl;
            continue;
        }
        //f=1;
        for(j=1;j<m-1;j++) {
            f=1;
            for(k=0;k<n;k++) {
                if (a[k][j]==0) f=0;
            }
            if (f==1) break;
        }
        if (f==1) {
            cout<<2<<endl;
            continue;
        }

        f=1;
        for(j=0;j<n;j++) {
            if (a[j][0]==1) f=0;
        }
        if (f==0) {
            cout<<3<<endl;
            continue;
        }
        f=1;
        for(j=0;j<n;j++) {
            if (a[j][m-1]==1) f=0;
        }
        if (f==0) {
            cout<<3<<endl;
            continue;
        }
        f=1;
        for(j=0;j<m;j++) {
            if (a[0][j]==1) f=0;
        }
        if (f==0) {
            cout<<3<<endl;
            continue;
        }
        f=1;
        for(j=0;j<m;j++) {
            if (a[n-1][j]==1) f=0;
        }
        if (f==0) {
            cout<<3<<endl;
            continue;
        }

        cout<<4<<endl;
    }
    return 0;
}