#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {r=a%b;a=b;b=r;}
    return a;
}
int vv[405],fv[1005],v[30][30];
int main()
{
    long long i,j=0,n,pz=0,s=0,x,y,z,a,b,c,m,pr,cnt=0,mx=0,mxx=0,x1,y1,x2,y2,cx=0,cy=0,nr1=0,nr2=0;
    cin>>n;
    for(i=1;i<=n*n;++i)
    {
        cin>>vv[i];
        ++fv[vv[i]];
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            if(v[i][j]!=0)
                continue;
            int ned=4;
            if(n%2==1)
            {
                if(i==(n+1)/2)
                    ned/=2;
                if(j==(n+1)/2)
                    ned/=2;
            }
            int ii,val;
            if(ned==1)
            {
                for(ii=1;ii<=1000;++ii)
                {
                    if(fv[ii])
                    if(fv[ii]%2)
                    {
                        val=ii;
                        --fv[ii];
                        break;
                    }
                }
                if(ii==1001)
                {
                    cout<<"NO";
                    return 0;
                }
                ii=val;
                v[i][j]=ii;
            }
            else if (ned==2)
            {
                for(ii=1;ii<=1000;++ii)
                {
                    if(fv[ii])
                    if(fv[ii]%4==2)
                    {
                        val=ii;
                        fv[ii]-=2;
                        break;
                    }
                }
                if(ii==1001)
                for(ii=1;ii<=1000;++ii)
                {
                    if(fv[ii])
                    if(fv[ii]>=2)
                    {
                        val=ii;
                        fv[ii]-=2;
                        break;
                    }
                }
                if(ii==1001)
                {
                    cout<<"NO";
                    return 0;
                }
                ii=val;
                v[i][j]=ii;
                v[n+1-i][j]=ii;
                v[i][n+1-j]=ii;
                v[n+1-i][n+1-j]=ii;
            }
            else
            {
                for(ii=1;ii<=1000;++ii)
                {
                    if(fv[ii])
                    if(fv[ii]>=4)
                    {
                        val=ii;
                        fv[ii]-=4;
                        break;
                    }
                }
                if(ii==1001)
                {
                    cout<<"NO";
                    return 0;
                }
                ii=val;
                v[i][j]=ii;
                v[n+1-i][j]=ii;
                v[i][n+1-j]=ii;
                v[n+1-i][n+1-j]=ii;
            }
        }
    cout<<"YES\n";
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
            cout<<v[i][j]<<' ';
        cout<<'\n';
    }
}