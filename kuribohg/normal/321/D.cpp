#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=1000000000;
int n,k,a[40][40],ans,c[40];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    k=(n+1)>>1;
    ans=-INF;
    for(int state=0;state<(1<<k);state++)
    {
        int res=0;
        for(int i=0;i<k;i++)
            if(state&(1<<i)) res-=a[k][i+1],c[i+1]=1;
            else res+=a[k][i+1],c[i+1]=0;
        for(int i=k+1;i<=n;i++)
            if(c[k]^c[i-k]) res-=a[k][i],c[i]=1;
            else res+=a[k][i],c[i]=0;
        for(int i=1;i<k;i++)
        {
            int res_neg=0,res_pos=0;
            for(int j=1;j<k;j++)
            {
                int neg=0,pos=0;
                neg-=a[i][j];
                neg+=a[i][j+k];
                if(c[j]) neg+=a[i+k][j];
                else neg-=a[i+k][j];
                if(c[j+k]) neg-=a[i+k][j+k];
                else neg+=a[i+k][j+k];
                if(neg<0) neg=-neg;
                pos+=a[i][j];
                pos+=a[i][j+k];
                if(c[j]) pos-=a[i+k][j];
                else pos+=a[i+k][j];
                if(c[j+k]) pos-=a[i+k][j+k];
                else pos+=a[i+k][j+k];
                if(pos<0) pos=-pos;
                res_neg+=neg,res_pos+=pos;
            }
            res_neg-=a[i][k],res_pos+=a[i][k];
            if(c[k]) res_neg+=a[i+k][k],res_pos-=a[i+k][k];
            else res_neg-=a[i+k][k],res_pos+=a[i+k][k];
            res+=max(res_neg,res_pos);
        }
        ans=max(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}