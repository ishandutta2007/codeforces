#include<bits/stdc++.h>
using namespace std;

const int nmax=5e2+42;

int n,m;
int inp[nmax][nmax],pref[nmax][nmax];

int sum(int x1,int y1,int x2,int y2)
{
    return pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1];
}

int sum_not(int x1,int y1,int x2,int y2)
{
    return (x2-x1+1)*(y2-y1+1)-(pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1]);
}

int solve()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char c=getchar();
            while(c!='0'&&c!='1')c=getchar();
            inp[i][j]=c-'0';
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+inp[i][j];

    int outp=n*m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            for(int i1=i+4;i1<=n&&sum(i+1,j+1,i1-1,j+2)+sum_not(i+1,j,i1-1,j)+sum_not(i,j+1,i,j+2)<outp;i1++)
            {
                for(int j1=j+3;j1<=m;j1++)
                {
                    int cur=sum(i+1,j+1,i1-1,j1-1)+sum_not(i,j+1,i,j1-1)+sum_not(i+1,j,i1-1,j);

                    if(cur>=outp)break;

                    cur+=sum_not(i1,j+1,i1,j1-1)+sum_not(i+1,j1,i1-1,j1);

                    outp=min(outp,cur);
                }
            }
        }

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%i\n",solve());
    }

    return 0;
}