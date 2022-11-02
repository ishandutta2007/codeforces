#include<bits/stdc++.h>
using namespace std;
long long i,j,k,l,p,o,u,n,h=1,id1,id2;
long long r1,c1,r2,c2,maxx=1e18;
char d[100][100];
int f[100][100];
void fllush(long long z,long long x)
{
    //cout<<z<<" "<<x<<"\n";
    if(f[z][x]==0)
    {
        f[z][x]=h;
        //cout<<h<<"\n";
        if(z+1<n)
        fllush(z+1,x);
        if(z-1>-1)
        fllush(z-1,x);
        if(x+1<n)
        fllush(z,x+1);
        if(x>0)
        fllush(z,x-1);
    }
}
int main()
{
    cin>>n;
    cin>>r1>>c1>>r2>>c2;
    for(i=0;i<n;i++)
    {
        scanf("%s",&d[i]);
        for(j=0;j<n;j++)
        {
            if(d[i][j]=='0')
            {
                f[i][j]=0;
            }
            else f[i][j]=1;
        }
    }
    //cout<<d[1][1]<<"\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(f[i][j]==0)
            {
                h++;
                //cout<<i<<" "<<j<<"\n";
                fllush(i,j);
            }
        }
    }
    //cout<<f[0][0]<<"\n";
    //cout<<f[4][4]<<"\n";
    id1=f[r1-1][c1-1]; id2=f[r2-1][c2-1];
    //cout<<id1<<id2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(f[i][j]==id1)
            {
                for(k=0;k<n;k++)
                {
                    for(l=0;l<n;l++)
                    {
                        if(f[k][l]==id2)
                        {
                            if(maxx>(k-i)*(k-i)+(l-j)*(l-j))
                                maxx=(k-i)*(k-i)+(l-j)*(l-j);
                        }
                    }
                }
            }
        }
    }
    cout<<maxx;
    //cout<<id1;
    return 0;
}