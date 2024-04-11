#include <bits/stdc++.h>
using namespace std;

//int a[101][101],b[101][101];
int main(){
    int i,j,k,l,m,n,t,r,b,d;
    cin>>t;
    /*a[1][1]=0;
    for(i=2;i<=100;i++) {
        a[1][i]=a[1][i-1]+1;
        b[1][i]=a[1][i];
        a[i][1]=a[i-1][1]+1;
        b[i][1]=a[i][1];
    }
    for(i=2;i<=100;i++) {
        for(j=2;j<=100;j++) {
            m=a[i][j-1]+i;
            if (m<a[i-1][j]+j) m=a[i-1][j]+j;
            a[i][j]=m;
            m=b[i][j-1]+i;
            if (m>b[i-1][j]+j) m=b[i-1][j]+j;
            b[i][j]=m;
        }
    }*/
    for(i=0;i<t;i++) {
        cin>>m>>n>>k;
        if (m>n) {
            m=m+n;
            n=m-n;
            m=m-n;
        }
        if (k==n*m-1) {
        //if ((k>=b[m][n])&&(k<=a[m][n])) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }
    return 0;
}