#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long int g[6][6],ans=0;
int n,i,j,k,l,m,a[6],b[6],c[6];
long int s(int a,int b,int c,int d,int e)
{
    return g[a][b]+g[b][a]+g[c][d]+g[d][c]+g[b][c]+g[c][b]+g[d][e]+g[e][d]+g[c][d]+g[d][c]+g[d][e]+g[e][d];
}
void hoanvi()
{
    int k;
    for (k=1;k<=5;k++)
    if (b[k]==0)
    {
        j++;
        c[j]=a[k];
        b[k]=1;
        if (j==5)
        {
            //printf("%d\n",s(c[1],c[2],c[3],c[4],c[5]));
            if(s(c[1],c[2],c[3],c[4],c[5])>ans) ans=s(c[1],c[2],c[3],c[4],c[5]);
        }
        
        hoanvi();
        b[k]=0;
        j--;
    }
}
int main(void)
{
    for (m=1;m<=5;m++) {a[m]=m;b[m]=0;}
    for(i=1;i<6;i++)
    {
        for(l=1;l<6;l++) scanf("%ld",&g[i][l]);
    }
    hoanvi();
    printf("%ld",ans);
}