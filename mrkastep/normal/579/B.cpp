#include<stdio.h>
#include <algorithm>

using namespace std;

/*
int HOK( int a, int b)
{
    int d=a*b;
    while (a*b!=0)
    {
        if (a>b) a=a%b;
        else b=b%a;
    }
    d=d/max(a,b);
    return d;
}
*/
 
int m[1000][1000];
int mn[1000];

int main ()
{
#ifdef _DEBUG
    freopen ("input.txt","rt",stdin);
    freopen ("output.txt","wt",stdout);
/*#else
    freopen ("symposium.in","rt",stdin);                                            
    freopen ("symposium.out","wt",stdout);*/
#endif
#pragma warning(disable:4996)
 
    int x=0,y=0, n;
     scanf("%d",&n);
     
     for (int i=0;i<1000;i++)
     {
         mn[i]=0;
         for (int j=0;j<1000;j++)
             m[i][j]=0;
     }


     for (int i=0; i<2*n;i++)
     {
         for (int j=0;j<i;j++)
         {
             int l;
             scanf("%d",&l);
             m[j][i]=l;
             m[i][j]=l;
         }
     }
     
     for (int i=0; i<n;i++)
     {
         for (int i1=0;i1<2*n;i1++)
         {
             for (int j1=0; j1<2*n;j1++)
             {
                 if (m[i1][j1]>m[x][y]) {x=i1; y=j1;}
             }
         }
         mn[x]=y; mn[y]=x;
         for (int h=0;h<2*n;h++)
         { m[x][h]=0; m[h][x]=0; m[y][h]=0; m[h][y]=0;}
     }

     for (int i=0;i<2*n;i++)
         printf("%d ",mn[i]+1);
     
return 0;
}