#include <iostream>

using namespace std;
int a1[1001][1001],a2[1001][1001],a3[1001][1001],a4[1001][1001],af[2003][2003],n;
void prm ()
{
    int i,j,a;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            a=a1[i][j];
            a1[i][j]=a2[i][j];
            a2[i][j]=a3[i][j];
            a3[i][j]=a4[i][j];
            a4[i][j]=a;
        }
    }
}
int rez ()
{
    int i,j,ai=0,ap=0,ni=0,np=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            af[i][j]=a1[i][j];
    for(i=1;i<=n;++i)
        for(j=n+1;j<=2*n;++j)
            af[i][j]=a2[i][j-n];
    for(i=n+1;i<=2*n;++i)
        for(j=1;j<=n;++j)
            af[i][j]=a3[i-n][j];
    for(i=n+1;i<=2*n;++i)
        for(j=n+1;j<=2*n;++j)
            af[i][j]=a4[i-n][j-n];
    for(i=1;i<=2*n;++i)
    {
        for(j=1;j<=2*n;++j)
        {
            if((i+j)%2==0)
            {
                if(af[i][j]==1)
                    np++;
                else
                    ap++;
            }
            else
            {
                if(af[i][j]==1)
                    ni++;
                else
                    ai++;
            }
        }
    }
    return min(ap+ni,np+ai);
}
int main()
{
    int k,s=0,i,j,cnt,mn=99999999,a;
    char c;
    cin>>n;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            cin>>c;
            a1[i][j]=c-'0';
        }
  //  cin>>ws;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            cin>>c;
            a2[i][j]=c-'0';
        }
 //   cin>>ws;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            cin>>c;
            a3[i][j]=c-'0';
        }
 //   cin>>ws;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            cin>>c;
            a4[i][j]=c-'0';
        }
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    prm();
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            a=a1[i][j];
            a1[i][j]=a3[i][j];
            a3[i][j]=a;
        }
    }
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    prm();
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            a=a2[i][j];
            a2[i][j]=a3[i][j];
            a3[i][j]=a;
        }
    }
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    prm();
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            a=a4[i][j];
            a4[i][j]=a1[i][j];
            a1[i][j]=a;
        }
    }
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    prm();
    mn=min(mn,rez());
    cout<<mn;
    return 0;
}


/*
10101010101
01010101010
10101010101
01010101010
10101010101
01010101010
10101010101
01010101010
10101010101
01010101010
10101010101

10101010101
01010101010
10101010101
01010101010
10101010101
01010101010
10101010101
01010101010
10101010101
01010101010
10101010101

01010101010
10101010101
01010101010
10101010101
01010101010
10101010101
01010101010
10101010101
01010101010
10101010101
01010101010

01010101010
10101010101
01010101010
10101010101
01010101010
10101010101
01010101010
10101010101
01010101010
10101010101
01010101010
*/