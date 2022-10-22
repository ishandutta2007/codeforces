#include<bits/stdc++.h>

using namespace std;

#define pb push_back
const int maxi =1e6+10;
int a[maxi];
vector<int> v[maxi];
int n,m;
pair<int,int> b[maxi];
int x[maxi], y[maxi];
int xi1, xi2, yi1, yi2;

int on_sq(int x, int y)
{
    if (x==xi1 && y>=yi1 && y<=yi2) return 1;
    if (x==xi2 && y>=yi1 && y<=yi2) return 1;
    if (y==yi1 && x>=xi1 && x<=xi2) return 1;
    if (y==yi2 && x>=xi1 && x<=xi2) return 1;
    return 0;
}

int main()
{
    cin>>n;

    int m = 4*n+1;

    for (int i=1;i<=m;i++)
        scanf("%d%d",&x[i], &y[i]);

    for (int i=0;i<=60;i++)
        for (int j=0;j<=60;j++)
        for (int k=1;k<=60;k++)
    {
         xi1= i;
         xi2= i+k;
         yi1= j;
         yi2 = j+k;

         int tot = 0;
         int id = 0;
         for (int l=1;l<=m;l++)
            if (on_sq(x[l],y[l])) tot++; else
            id = l;

         if (tot ==m-1)
         {
             return !printf("%d %d\n",x[id],y[id]);
         }
    }
    return 0;
}