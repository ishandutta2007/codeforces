#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,x,y;
    int a[501],b[501][501];
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    memset(b,0,sizeof(b));
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) b[i][j]=-1;
    }
    for(i=0;i<n;i++) {
        b[i][i]=a[i];
        x=y=i;
        for(j=1;j<a[i];j++) {
            if ((x>0)&&(b[x-1][y]==0)) x--;
            else if ((y>0)&&(b[x][y-1]==0)) y--;
            else if (y==0) {
                while (b[x][0]!=0) x++;
                if (x<i) {
                    while ((y<x)&&(b[x][y]==0)) y++;
                    y--;
                }
            }
            else if (x<n-1){
                x++;
            }
            else y++;
            b[x][y]=a[i];
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<=i;j++) {
            cout<<b[i][j]<<' '; 
        }
        cout<<endl;
    }
    return 0;
}