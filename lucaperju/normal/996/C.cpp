#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
/*
for(i=1;i<=n;++i)
*/
int v[10][55],rez[20000][3],cnt,n;
void prm ()
{
    int i,a=v[3][n],lin=0,poz=0,lnc,pzc,lnv,pzv;
    for(i=1; i<=n; ++i)
    {
        if(v[2][i]==0)
        {
            lin=2;
            poz=i;
            break;
        }
        if(v[3][i]==0)
        {
            lin=3;
            poz=i;
            break;
        }
    }
    lnv=lin;
    pzv=poz;
    if(lnv==2)
    {
        if(pzv!=1)
        {
            lnc=2;
            pzc=pzv-1;
        }
        else
        {
            lnc=3;
            pzc=1;
        }
    }
    else
    {
        if(pzv!=n)
        {
            lnc=3;
            pzc=pzv+1;
        }
        else
        {
            lnc=2;
            pzc=n;
        }
    }
    while(lnc!=lin || pzc!=poz)
    {
        if(v[lnc][pzc]!=0)
        {
            rez[++cnt][0]=v[lnc][pzc];
            rez[cnt][1]=lnv;
            rez[cnt][2]=pzv;
        }
        v[lnv][pzv]=v[lnc][pzc];
        lnv=lnc;
        pzv=pzc;
        if(lnv==2)
        {
            if(pzv!=1)
            {
                lnc=2;
                pzc=pzv-1;
            }
            else
            {
                lnc=3;
                pzc=1;
            }
        }
        else
        {
            if(pzv!=n)
            {
                lnc=3;
                pzc=pzv+1;
            }
            else
            {
                lnc=2;
                pzc=n;
            }
        }
    }
    v[lnv][pzv]=0;
    /*  if(v[2][n]!=0)
      {
          rez[++cnt][0]=v[2][n];
          rez[cnt][1]=3;
          rez[cnt][2]=n;
      }
      v[3][n]=v[2][n];
      for(i=n-1;i>=1;--i)
      {
          if(v[2][i]!=0)
          {
              rez[++cnt][0]=v[2][i];
              rez[cnt][1]=2;
              rez[cnt][2]=i+1;
          }
          v[2][i+1]=v[2][i];
      }
      if(v[3][1]!=0)
      {
          rez[++cnt][0]=v[3][1];
          rez[cnt][1]=2;
          rez[cnt][2]=1;
      }
      v[2][1]=v[3][1];
      for(i=2;i<n;++i)
      {
          if(v[3][i]!=0)
          {
              rez[++cnt][0]=v[3][i];
              rez[cnt][1]=3;
              rez[cnt][2]=i-1;
          }
          v[3][i-1]=v[3][i];
      }
      if(a!=0)
      {
          rez[++cnt][0]=a;
          rez[cnt][1]=3;
          rez[cnt][2]=n-1;
      }
      v[3][n-1]=a;
      */
}
int main()
{
    long long i,j,a,b,c,mx=2250000000000,mn=-2250000000000,ok=1,k;
    cin>>n>>k;
    for(i=1; i<=4; ++i)
        for(j=1; j<=n; ++j)
            cin>>v[i][j];
    if(n==1)
    {
        if(v[1][1]==v[2][1] && k==2)
        {
            cout<<2<<'\n'<<v[1][1]<<' '<<1<<' '<<1<<'\n'<<v[4][1]<<' '<<4<<' '<<1;
        }
        else if(k==2)
            cout<<-1;
        else
        {
            if(v[2][1]==1 && v[1][1]==1)
                cout<<1<<'\n'<<1<<' '<<1<<' '<<1;
            else if(v[3][1]==1 && v[4][1]==1)
                cout<<1<<'\n'<<1<<' '<<4<<' '<<1;
            else if(v[2][1]==1 && v[4][1]==1)
                cout<<2<<'\n'<<1<<' '<<3<<' '<<1<<'\n'<<1<<' '<<4<<' '<<1;
            else if(v[3][1]==1 && v[1][1]==1)
                cout<<2<<'\n'<<1<<' '<<2<<' '<<1<<'\n'<<1<<' '<<1<<' '<<1;
        }
    }
    else
    {
        if(k==2*n)
        {
            for(i=1; i<=n; ++i)
                if(v[1][i]==v[2][i] || v[3][i]==v[4][i])
                    ok=0;
            if(ok==1)
            {
                cout<<-1;
                return 0;
            }
        }
        while(k>0)
        {
            for(i=1; i<=n; ++i)
            {
                if(v[1][i]==v[2][i] && v[1][i]!=0)
                {
                    v[2][i]=0;
                    rez[++cnt][0]=v[1][i];
                    rez[cnt][1]=1;
                    rez[cnt][2]=i;
                    --k;
                }
                if(v[3][i]==v[4][i] && v[3][i]!=0)
                {
                    v[3][i]=0;
                    rez[++cnt][0]=v[4][i];
                    rez[cnt][1]=4;
                    rez[cnt][2]=i;
                    --k;
                }
            }
            prm();
        }
        cout<<cnt<<'\n';
        for(i=1; i<=cnt; ++i)
        {
            for(j=0; j<=2; ++j)
                cout<<rez[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}