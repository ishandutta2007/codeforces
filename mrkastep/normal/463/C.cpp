#include <stdio.h>
#include <algorithm>
#include <vector>
#define For(i,n) for(i=0;i<(n);i++)

int t[2000][2000];
long long int ds[4500],ds1[4500];

void solve(int n){
    int i,j,x,x1=1,y1=1,x2=1,y2=2;
    long long int m1=0,m2=0;
    For(i,4500) ds[i]=0;
    For(i,4500) ds1[i]=0;
    For(i,n) For(j,n){
        scanf("%d",&x);
        t[i][j]=x;
        ds[i+j]+=x;
        ds1[i-j+2000]+=x;
    }
/*  For(i,n){
        For(j,n) printf("%I64d ",ds[j][i]);
        printf("\n");
    }*/
    For(i,n) For(j,n){
        if((i+j)%2==0){
            if(ds[i+j]+ds1[i-j+2000]-t[i][j]>m1){
                m1=ds[i+j]+ds1[i-j+2000]-t[i][j];
                x1=j+1;
                y1=i+1;
            }
        }else{ 
            if(ds[i+j]+ds1[i-j+2000]-t[i][j]>m2){
                m2=ds[i+j]+ds1[i-j+2000]-t[i][j];
                x2=j+1;
                y2=i+1;
            }
        }
    }
    printf("%I64d\n",m1+m2);
    printf("%d %d %d %d",y1,x1,y2,x2);
}

int main() {
#pragma comment(linker, "/STACK:67108864")
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
    int n;
    while(scanf("%d",&n)!=EOF){
    solve(n);
    }
    return 0;
}