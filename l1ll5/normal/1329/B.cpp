#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 40
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int bin[N];
int f[N][N];
main()
{
    bin[0]=1;
    for(int i=1;i<=39;i++) bin[i]=bin[i-1]<<1;

    int t=read();
    int ans=0;
    while(t--)
    {
        ans=0;
        int d=read(),m=read();
        if(d==1)
        {
            ans=1%m;
            printf("%lld\n",ans);
            continue ;
        }
        int l=0;
        int tmp=d;
        while(tmp) l++,tmp>>=1;
        int lst=d-bin[l-1]+1;
        memset(f,0,sizeof(f));
        f[0][0]=1;

    //    cerr<<lst<<endl;
        for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=l;j++)
            {
                for(int k=0;k<j;k++)
                {
                    int flag;
                    if(j==l) flag=lst;
                    else flag=bin[j-1];

                //    if(j==1) flag--;

                    f[i][j]+=f[i-1][k]*flag%m;
                    f[i][j]%=m;
                }
            }
        }
     /*  for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=l;j++)
            cout<<f[i][j]<<' ';
            cout<<endl;
        }*/
        for(int i=1;i<=l;i++) for(int j=1;j<=l;j++) ans+=f[i][j] , ans%=m;

        printf("%lld\n",ans);
    }
}