#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 520
#define oo 1000000000
using namespace std;
int bs[10];
int ans[10][N][N];
int n,k,i,j;
int main(){
	bs[0]=1;
	rpt(i,1,9) bs[i]=bs[i-1]<<1;
	ans[1][0][0]=ans[1][0][1]=ans[1][1][0]=1;
	
    scanf("%d",&n);
    rpt(k,2,n){
    	rpt(i,0,bs[k]-1) rpt(j,0,bs[k]-1) ans[k][i][j]=ans[k-1][i][j/2];
        rpt(i,0,bs[k-1]-1) rpt(j,0,bs[k]-1){
            if (j&1) ans[k][i+bs[k-1]][j]=1-ans[k-1][i][j/2];
			else ans[k][i+bs[k-1]][j]=ans[k-1][i][j/2];
        }
    }
    
    rpt(i,0,bs[n]-1){
    	rpt(j,0,bs[n]-1){
            if(ans[n][i][j]) printf("+");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}