#include <bits/stdc++.h>
using namespace std;
char v[100005];
char st[100005];
int stpz[100005];
int prevv[100005];
char rz[100005][12];
int valrz[100005];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k=0,n,q,m,ans=0,sx,sy,fx,fy;
    cin>>(v+1);
    n=strlen(v+1);
    for(i=n;i>=1;--i)
    {
        st[++k]=v[i];
        if(st[k-1]==st[k])
            prevv[k]=prevv[k-1];
        else
            prevv[k]=k-1;
        stpz[k]=i;
        if(st[k]==st[k-1])
        {
            if(k>=2 && st[k-1]>st[prevv[k-1]] && stpz[k]+1==stpz[k-1])
                k-=2;
        }
        valrz[i]=k;
        if(k<=10)
        {
            for(j=1;j<=k;++j)
                rz[i][k-j+1]=st[j];
        }
        else
        {
            rz[i][1]=st[k];
            rz[i][2]=st[k-1];
            rz[i][3]=st[k-2];
            rz[i][4]=st[k-3];
            rz[i][5]=st[k-4];
            rz[i][6]='.';
            rz[i][7]='.';
            rz[i][8]='.';
            rz[i][9]=st[2];
            rz[i][10]=st[1];
        }
    }
    for(i=1;i<=n;++i)
    {
        cout<<valrz[i]<<' '<<(rz[i]+1)<<'\n';
    }
    return 0;
}