#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

int n,m;
char inp[nmax];

int where(int x,int y)
{
    return y+m*(x-1);
}

bool can[nmax];
bool is[nmax];

bool actual[nmax];

int pref[nmax];

int ask(int x,int y)
{
    if(x==0||y==0)return 0;
    return pref[where(x,y)];
}
int sum(int x1,int y1,int x2,int y2)
{
    return ask(x2,y2)+ask(x1-1,y1-1)-ask(x1-1,y2)-ask(x2,y1-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>inp[where(i,j)];
        }

    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
        {
            if(i==n&&j==m){can[where(n,m)]=1;continue;}
            if(inp[where(i,j)]=='#'){can[where(i,j)]=0;continue;}
            else
            {
                if(i!=n)can[where(i,j)]=can[where(i+1,j)];
                if(j!=m&&can[where(i,j)]==0)can[where(i,j)]=can[where(i,j+1)];
            }
        }

    if(can[where(1,1)]==0)
    {
        cout<<0<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1){is[where(1,1)]=1;continue;}
            if(inp[where(i,j)]=='#'){is[where(i,j)]=0;continue;}
            else
            {
                if(i!=1)is[where(i,j)]=is[where(i-1,j)];
                if(j!=1&&is[where(i,j)]==0)is[where(i,j)]=is[where(i,j-1)];
            }
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            {
                actual[where(i,j)]=can[where(i,j)]&&is[where(i,j)];
                //cout<<i<<" "<<j<<" -> "<<actual[where(i,j)]<<endl;
            }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        pref[where(i,j)]=actual[where(i,j)];

        if(i!=1)pref[where(i,j)]+=pref[where(i-1,j)];
        if(j!=1)pref[where(i,j)]+=pref[where(i,j-1)];

        if(i!=1&&j!=1)pref[where(i,j)]-=pref[where(i-1,j-1)];

        //cout<<i<<" "<<j<<" -> "<<pref[where(i,j)]<<endl;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(actual[where(i,j)])
            {
                if(i==1&&j==1)continue;
                if(i==n&&j==m)continue;

                if(sum(1,1,i,j)+sum(i,j,n,m)-1==sum(1,1,n,m))
                {

                    cout<<1<<endl;
                    return 0;
                }
            }

    cout<<2<<endl;

    return 0;
}